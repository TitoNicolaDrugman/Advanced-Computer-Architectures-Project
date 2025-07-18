/**
 ******************************************************************************
 * @file    ai_atonn_wrapper.h
 * @author  GPM/AIS Application Team
 * @brief   AI ATONN wrapper - helper functions
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023, 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/* Description
 *
 * - Simple app wrapper to use the LL aton runtime
 *
 * History:
 *  - v0.1 - initial version
 *  - v0.2 - add NPU counters
 *  - v0.3 - rework management of the NPU counters (see ai_wrapper_ATON.h file)
 *
 * TODO
 *  - see aiValidation_ATON.c file
 */

#ifndef __AI_NPU_WRAPPER_H__
#define __AI_NPU_WRAPPER_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "ll_aton_runtime.h"

#define USE_NPU_CACHE
#define USE_NPU_COUNTERS                1

#define NPU_NETWORK_NUMBER      (1)   /* number of embedded model */


#define NPU_MAX_IO_BUFFER       (32)
#define NPU_MAX_COUNTERS        (16)  /* see ATON IP spec */

/* COUNTER options */
#define COUNTER_OPT_EPOCH_LEN           (1 << 0)
#define COUNTER_OPT_STRG_ACTIVE         (1 << 1)
#define COUNTER_OPT_STRG_HENV           (1 << 2)
#define COUNTER_OPT_BUSIF_RW_DATA       (1 << 3)
#define COUNTER_OPT_NPU_CACHE           (1 << 4)
#define COUNTER_OPT_STRG_I_ACTIVE       (1 << 5) 
#define COUNTER_OPT_STRG_O_ACTIVE       (1 << 6) 

/* COUNTER format/status */
#define COUNTER_FMT_OPT_SHIFT           (8)
#define COUNTER_FMT_NUMBER(_fmt_)       ((_fmt_) & 0xFF)
#define COUNTER_FMT_OPT(_opt_)          ((_opt_) << COUNTER_FMT_OPT_SHIFT)


/* Perfmeters/counters for the current epoch */
struct npu_epoch_counters {
  uint32_t cpu_start;                   /* PRE - cpu cycles */
  uint32_t cpu_core;                    /* NPU Core - cpu cycles */
  uint32_t cpu_end;                     /* POST - cpu cycles */
  uint32_t npu_start;                   /* PRE - npu cycles */
  uint32_t npu_core;                    /* NPU core - npu cycles */
  uint32_t npu_end;                     /* POST - npu cycles */
  uint32_t counter_fmt;                 /* b31..b8 : format b7..b0 : number of counters */
  uint32_t counters[NPU_MAX_COUNTERS];
  uint32_t cache_counters[8];           /* NPU/AXICACHE counters */
};

/* Perfmeters/conters for the current inference */
struct npu_counters {
  uint64_t cpu_start;                   /* Cumulated MCU cycles to prepare the epoch blocks */
  uint64_t cpu_core;                    /* Cumulated MCU cycles to execute the epoch blocks */
  uint64_t cpu_end;                     /* Cumulated MCU cycles to finalize the epoch blocks */
  uint64_t cpu_all;                     /* Cumulated MCU cycles (out-of-the box) */
  uint64_t extra;                       /* extra */
};

/* Model info */
struct npu_model_info {
  const char *name;                     /* Model name - string */
  const char *compile_datetime;         /* Compilation datetime */
  const char *rt_desc;                  /* Short human description of the RT */
  uint32_t version;                     /* Version of the RT code */
  uint32_t n_inputs;                    /* Number of inputs */
  uint32_t n_outputs;                   /* Number of outputs */
  const LL_Buffer_InfoTypeDef* in_bufs[NPU_MAX_IO_BUFFER];    /* input buffers */
  const LL_Buffer_InfoTypeDef* out_bufs[NPU_MAX_IO_BUFFER];   /* output buffers */
  uint32_t n_epochs;                    /* Number of generated epoch */
  uint32_t activations;                 /* Size in byte of the activations */
  uint32_t params;                      /* Size in bytes of the parameters */
};

/* user cb - called at the end of the epoch POST_END event */
typedef void (*npu_user_cb)(const LL_ATON_RT_Callbacktype_t ctype,
                            const int16_t cidx,
                            const LL_ATON_RT_EpochBlockItem_t *epoch_block,
                            struct npu_epoch_counters *counters);

/* model instance */
struct npu_instance {
  uint32_t state;
  struct npu_model_info info;
  NN_Instance_TypeDef *impl;
  npu_user_cb user_cb;
  uint32_t option;
};


/*
 * Helper functions
 */

uint32_t get_ll_buffer_size(const LL_Buffer_InfoTypeDef *ll_buf_info);
uint32_t get_ll_element_size(const LL_Buffer_InfoTypeDef *ll_buf_info);


#define _MAX_N_DIMS (6 + 2) /* + for atonn batch dims */

struct _shape_desc {
  uint32_t ndims;
  uint32_t shape[_MAX_N_DIMS];
};


/*
 * Wrapper entry points
 */

int npu_get_instance_by_index(int idx, struct npu_instance *instance);
int npu_init(struct npu_instance *instance, uint32_t mode);
int npu_set_callback(struct npu_instance *instance, npu_user_cb user_cb);

int npu_run(struct npu_instance *instance, struct npu_counters *counters);


#endif /* __AI_NPU_WRAPPER_H__ */
