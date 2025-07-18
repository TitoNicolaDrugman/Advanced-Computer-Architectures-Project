/**
 ******************************************************************************
 * @file    ai_io_buffers_ATON.c
 * @author  MCD/AIS Team
 * @brief   AI Validation application (entry points) - IO buffers allocation
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software is licensed under terms that can be found in the LICENSE file in
 * the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "ai_io_buffers_ATON.h"
#include "ll_aton_NN_interface.h"
#include "network.h"


/* ------ Allocated inputs ------ */

#if (defined(LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS) && (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS > 0))
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 1)
static int8_t data_in_1[LL_ATON_DEFAULT_IN_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_1_ALIGNMENT));
#endif   /* USER_ALLOCATED_INPUTS == 1 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 2)
static int8_t data_in_1[LL_ATON_DEFAULT_IN_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_1_ALIGNMENT));
static int8_t data_in_2[LL_ATON_DEFAULT_IN_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_2_ALIGNMENT));
#endif   /* USER_ALLOCATED_INPUTS == 2 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 3)
static int8_t data_in_1[LL_ATON_DEFAULT_IN_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_1_ALIGNMENT));
static int8_t data_in_2[LL_ATON_DEFAULT_IN_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_2_ALIGNMENT));
static int8_t data_in_3[LL_ATON_DEFAULT_IN_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_3_ALIGNMENT));
#endif   /* USER_ALLOCATED_INPUTS == 3 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 4)
static int8_t data_in_1[LL_ATON_DEFAULT_IN_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_1_ALIGNMENT));
static int8_t data_in_2[LL_ATON_DEFAULT_IN_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_2_ALIGNMENT));
static int8_t data_in_3[LL_ATON_DEFAULT_IN_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_3_ALIGNMENT));
static int8_t data_in_4[LL_ATON_DEFAULT_IN_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_4_ALIGNMENT));
#endif   /* USER_ALLOCATED_INPUTS == 4 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 5)
static int8_t data_in_1[LL_ATON_DEFAULT_IN_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_1_ALIGNMENT));
static int8_t data_in_2[LL_ATON_DEFAULT_IN_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_2_ALIGNMENT));
static int8_t data_in_3[LL_ATON_DEFAULT_IN_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_3_ALIGNMENT));
static int8_t data_in_4[LL_ATON_DEFAULT_IN_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_4_ALIGNMENT));
static int8_t data_in_5[LL_ATON_DEFAULT_IN_5_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_5_ALIGNMENT));
#endif   /* USER_ALLOCATED_INPUTS == 5 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 6)
static int8_t data_in_1[LL_ATON_DEFAULT_IN_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_1_ALIGNMENT));
static int8_t data_in_2[LL_ATON_DEFAULT_IN_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_2_ALIGNMENT));
static int8_t data_in_3[LL_ATON_DEFAULT_IN_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_3_ALIGNMENT));
static int8_t data_in_4[LL_ATON_DEFAULT_IN_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_4_ALIGNMENT));
static int8_t data_in_5[LL_ATON_DEFAULT_IN_5_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_5_ALIGNMENT));
static int8_t data_in_6[LL_ATON_DEFAULT_IN_6_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_6_ALIGNMENT));
#endif   /* USER_ALLOCATED_INPUTS == 6 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 7)
static int8_t data_in_1[LL_ATON_DEFAULT_IN_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_1_ALIGNMENT));
static int8_t data_in_2[LL_ATON_DEFAULT_IN_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_2_ALIGNMENT));
static int8_t data_in_3[LL_ATON_DEFAULT_IN_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_3_ALIGNMENT));
static int8_t data_in_4[LL_ATON_DEFAULT_IN_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_4_ALIGNMENT));
static int8_t data_in_5[LL_ATON_DEFAULT_IN_5_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_5_ALIGNMENT));
static int8_t data_in_6[LL_ATON_DEFAULT_IN_6_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_6_ALIGNMENT));
static int8_t data_in_7[LL_ATON_DEFAULT_IN_7_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_7_ALIGNMENT));
#endif   /* USER_ALLOCATED_INPUTS == 7 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 8)
static int8_t data_in_1[LL_ATON_DEFAULT_IN_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_1_ALIGNMENT));
static int8_t data_in_2[LL_ATON_DEFAULT_IN_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_2_ALIGNMENT));
static int8_t data_in_3[LL_ATON_DEFAULT_IN_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_3_ALIGNMENT));
static int8_t data_in_4[LL_ATON_DEFAULT_IN_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_4_ALIGNMENT));
static int8_t data_in_5[LL_ATON_DEFAULT_IN_5_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_5_ALIGNMENT));
static int8_t data_in_6[LL_ATON_DEFAULT_IN_6_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_6_ALIGNMENT));
static int8_t data_in_7[LL_ATON_DEFAULT_IN_7_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_7_ALIGNMENT));
static int8_t data_in_8[LL_ATON_DEFAULT_IN_8_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_8_ALIGNMENT));
#endif   /* USER_ALLOCATED_INPUTS == 8 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 9)
static int8_t data_in_1[LL_ATON_DEFAULT_IN_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_1_ALIGNMENT));
static int8_t data_in_2[LL_ATON_DEFAULT_IN_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_2_ALIGNMENT));
static int8_t data_in_3[LL_ATON_DEFAULT_IN_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_3_ALIGNMENT));
static int8_t data_in_4[LL_ATON_DEFAULT_IN_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_4_ALIGNMENT));
static int8_t data_in_5[LL_ATON_DEFAULT_IN_5_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_5_ALIGNMENT));
static int8_t data_in_6[LL_ATON_DEFAULT_IN_6_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_6_ALIGNMENT));
static int8_t data_in_7[LL_ATON_DEFAULT_IN_7_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_7_ALIGNMENT));
static int8_t data_in_8[LL_ATON_DEFAULT_IN_8_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_8_ALIGNMENT));
static int8_t data_in_9[LL_ATON_DEFAULT_IN_9_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_9_ALIGNMENT));
#endif   /* USER_ALLOCATED_INPUTS == 9 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 10)
static int8_t data_in_1[LL_ATON_DEFAULT_IN_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_1_ALIGNMENT));
static int8_t data_in_2[LL_ATON_DEFAULT_IN_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_2_ALIGNMENT));
static int8_t data_in_3[LL_ATON_DEFAULT_IN_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_3_ALIGNMENT));
static int8_t data_in_4[LL_ATON_DEFAULT_IN_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_4_ALIGNMENT));
static int8_t data_in_5[LL_ATON_DEFAULT_IN_5_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_5_ALIGNMENT));
static int8_t data_in_6[LL_ATON_DEFAULT_IN_6_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_6_ALIGNMENT));
static int8_t data_in_7[LL_ATON_DEFAULT_IN_7_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_7_ALIGNMENT));
static int8_t data_in_8[LL_ATON_DEFAULT_IN_8_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_8_ALIGNMENT));
static int8_t data_in_9[LL_ATON_DEFAULT_IN_9_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_9_ALIGNMENT));
static int8_t data_in_10[LL_ATON_DEFAULT_IN_10_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_IN_10_ALIGNMENT));
#endif   /* USER_ALLOCATED_INPUTS == 10 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS > 10)
#error "LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS is too large"
#endif
#endif   /* LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS */

/* ------ Allocated outputs ------ */

#if (defined(LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS) && (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS > 0))
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 1)
static int8_t data_out_1[LL_ATON_DEFAULT_OUT_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_1_ALIGNMENT));
#endif   /* USER_ALLOCATED_OUTPUTS == 1 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 2)
static int8_t data_out_1[LL_ATON_DEFAULT_OUT_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_1_ALIGNMENT));
static int8_t data_out_2[LL_ATON_DEFAULT_OUT_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_2_ALIGNMENT));
#endif   /* USER_ALLOCATED_OUTPUTS == 2 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 3)
static int8_t data_out_1[LL_ATON_DEFAULT_OUT_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_1_ALIGNMENT));
static int8_t data_out_2[LL_ATON_DEFAULT_OUT_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_2_ALIGNMENT));
static int8_t data_out_3[LL_ATON_DEFAULT_OUT_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_3_ALIGNMENT));
#endif   /* USER_ALLOCATED_OUTPUTS == 3 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 4)
static int8_t data_out_1[LL_ATON_DEFAULT_OUT_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_1_ALIGNMENT));
static int8_t data_out_2[LL_ATON_DEFAULT_OUT_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_2_ALIGNMENT));
static int8_t data_out_3[LL_ATON_DEFAULT_OUT_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_3_ALIGNMENT));
static int8_t data_out_4[LL_ATON_DEFAULT_OUT_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_4_ALIGNMENT));
#endif   /* USER_ALLOCATED_OUTPUTS == 4 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 5)
static int8_t data_out_1[LL_ATON_DEFAULT_OUT_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_1_ALIGNMENT));
static int8_t data_out_2[LL_ATON_DEFAULT_OUT_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_2_ALIGNMENT));
static int8_t data_out_3[LL_ATON_DEFAULT_OUT_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_3_ALIGNMENT));
static int8_t data_out_4[LL_ATON_DEFAULT_OUT_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_4_ALIGNMENT));
static int8_t data_out_5[LL_ATON_DEFAULT_OUT_5_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_5_ALIGNMENT));
#endif   /* USER_ALLOCATED_OUTPUTS == 5 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 6)
static int8_t data_out_1[LL_ATON_DEFAULT_OUT_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_1_ALIGNMENT));
static int8_t data_out_2[LL_ATON_DEFAULT_OUT_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_2_ALIGNMENT));
static int8_t data_out_3[LL_ATON_DEFAULT_OUT_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_3_ALIGNMENT));
static int8_t data_out_4[LL_ATON_DEFAULT_OUT_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_4_ALIGNMENT));
static int8_t data_out_5[LL_ATON_DEFAULT_OUT_5_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_5_ALIGNMENT));
static int8_t data_out_6[LL_ATON_DEFAULT_OUT_6_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_6_ALIGNMENT));
#endif   /* USER_ALLOCATED_OUTPUTS == 6 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 7)
static int8_t data_out_1[LL_ATON_DEFAULT_OUT_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_1_ALIGNMENT));
static int8_t data_out_2[LL_ATON_DEFAULT_OUT_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_2_ALIGNMENT));
static int8_t data_out_3[LL_ATON_DEFAULT_OUT_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_3_ALIGNMENT));
static int8_t data_out_4[LL_ATON_DEFAULT_OUT_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_4_ALIGNMENT));
static int8_t data_out_5[LL_ATON_DEFAULT_OUT_5_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_5_ALIGNMENT));
static int8_t data_out_6[LL_ATON_DEFAULT_OUT_6_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_6_ALIGNMENT));
static int8_t data_out_7[LL_ATON_DEFAULT_OUT_7_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_7_ALIGNMENT));
#endif   /* USER_ALLOCATED_OUTPUTS == 7 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 8)
static int8_t data_out_1[LL_ATON_DEFAULT_OUT_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_1_ALIGNMENT));
static int8_t data_out_2[LL_ATON_DEFAULT_OUT_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_2_ALIGNMENT));
static int8_t data_out_3[LL_ATON_DEFAULT_OUT_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_3_ALIGNMENT));
static int8_t data_out_4[LL_ATON_DEFAULT_OUT_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_4_ALIGNMENT));
static int8_t data_out_5[LL_ATON_DEFAULT_OUT_5_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_5_ALIGNMENT));
static int8_t data_out_6[LL_ATON_DEFAULT_OUT_6_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_6_ALIGNMENT));
static int8_t data_out_7[LL_ATON_DEFAULT_OUT_7_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_7_ALIGNMENT));
static int8_t data_out_8[LL_ATON_DEFAULT_OUT_8_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_8_ALIGNMENT));
#endif   /* USER_ALLOCATED_OUTPUTS == 8 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 9)
static int8_t data_out_1[LL_ATON_DEFAULT_OUT_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_1_ALIGNMENT));
static int8_t data_out_2[LL_ATON_DEFAULT_OUT_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_2_ALIGNMENT));
static int8_t data_out_3[LL_ATON_DEFAULT_OUT_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_3_ALIGNMENT));
static int8_t data_out_4[LL_ATON_DEFAULT_OUT_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_4_ALIGNMENT));
static int8_t data_out_5[LL_ATON_DEFAULT_OUT_5_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_5_ALIGNMENT));
static int8_t data_out_6[LL_ATON_DEFAULT_OUT_6_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_6_ALIGNMENT));
static int8_t data_out_7[LL_ATON_DEFAULT_OUT_7_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_7_ALIGNMENT));
static int8_t data_out_8[LL_ATON_DEFAULT_OUT_8_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_8_ALIGNMENT));
static int8_t data_out_9[LL_ATON_DEFAULT_OUT_9_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_9_ALIGNMENT));
#endif   /* USER_ALLOCATED_OUTPUTS == 9 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 10)
static int8_t data_out_1[LL_ATON_DEFAULT_OUT_1_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_1_ALIGNMENT));
static int8_t data_out_2[LL_ATON_DEFAULT_OUT_2_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_2_ALIGNMENT));
static int8_t data_out_3[LL_ATON_DEFAULT_OUT_3_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_3_ALIGNMENT));
static int8_t data_out_4[LL_ATON_DEFAULT_OUT_4_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_4_ALIGNMENT));
static int8_t data_out_5[LL_ATON_DEFAULT_OUT_5_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_5_ALIGNMENT));
static int8_t data_out_6[LL_ATON_DEFAULT_OUT_6_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_6_ALIGNMENT));
static int8_t data_out_7[LL_ATON_DEFAULT_OUT_7_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_7_ALIGNMENT));
static int8_t data_out_8[LL_ATON_DEFAULT_OUT_8_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_8_ALIGNMENT));
static int8_t data_out_9[LL_ATON_DEFAULT_OUT_9_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_9_ALIGNMENT));
static int8_t data_out_10[LL_ATON_DEFAULT_OUT_10_SIZE_BYTES] __attribute__((aligned LL_ATON_DEFAULT_OUT_10_ALIGNMENT));
#endif   /* USER_ALLOCATED_OUTPUTS == 10 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS > 10)
#error "LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS is too large"
#endif
#endif   /* LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS */

                
/* ------ External definitions from the .c file ------ */
                
extern LL_ATON_User_IO_Result_t LL_ATON_Set_User_Input_Buffer_Default(uint32_t num, void* buffer, uint32_t size);
extern LL_ATON_User_IO_Result_t LL_ATON_Set_User_Output_Buffer_Default(uint32_t num, void* buffer, uint32_t size);

/* ------ Utilities ------ */
                

void connect_input_buffers(void)
{
#if (defined(LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS) && (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS > 0))
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 1)
LL_ATON_Set_User_Input_Buffer_Default(0, data_in_1, LL_ATON_DEFAULT_IN_1_SIZE_BYTES);
#endif   /* USER_ALLOCATED_INPUTS == 1 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 2)
LL_ATON_Set_User_Input_Buffer_Default(0, data_in_1, LL_ATON_DEFAULT_IN_1_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(1, data_in_2, LL_ATON_DEFAULT_IN_2_SIZE_BYTES);
#endif   /* USER_ALLOCATED_INPUTS == 2 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 3)
LL_ATON_Set_User_Input_Buffer_Default(0, data_in_1, LL_ATON_DEFAULT_IN_1_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(1, data_in_2, LL_ATON_DEFAULT_IN_2_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(2, data_in_3, LL_ATON_DEFAULT_IN_3_SIZE_BYTES);
#endif   /* USER_ALLOCATED_INPUTS == 3 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 4)
LL_ATON_Set_User_Input_Buffer_Default(0, data_in_1, LL_ATON_DEFAULT_IN_1_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(1, data_in_2, LL_ATON_DEFAULT_IN_2_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(2, data_in_3, LL_ATON_DEFAULT_IN_3_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(3, data_in_4, LL_ATON_DEFAULT_IN_4_SIZE_BYTES);
#endif   /* USER_ALLOCATED_INPUTS == 4 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 5)
LL_ATON_Set_User_Input_Buffer_Default(0, data_in_1, LL_ATON_DEFAULT_IN_1_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(1, data_in_2, LL_ATON_DEFAULT_IN_2_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(2, data_in_3, LL_ATON_DEFAULT_IN_3_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(3, data_in_4, LL_ATON_DEFAULT_IN_4_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(4, data_in_5, LL_ATON_DEFAULT_IN_5_SIZE_BYTES);
#endif   /* USER_ALLOCATED_INPUTS == 5 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 6)
LL_ATON_Set_User_Input_Buffer_Default(0, data_in_1, LL_ATON_DEFAULT_IN_1_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(1, data_in_2, LL_ATON_DEFAULT_IN_2_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(2, data_in_3, LL_ATON_DEFAULT_IN_3_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(3, data_in_4, LL_ATON_DEFAULT_IN_4_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(4, data_in_5, LL_ATON_DEFAULT_IN_5_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(5, data_in_6, LL_ATON_DEFAULT_IN_6_SIZE_BYTES);
#endif   /* USER_ALLOCATED_INPUTS == 6 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 7)
LL_ATON_Set_User_Input_Buffer_Default(0, data_in_1, LL_ATON_DEFAULT_IN_1_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(1, data_in_2, LL_ATON_DEFAULT_IN_2_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(2, data_in_3, LL_ATON_DEFAULT_IN_3_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(3, data_in_4, LL_ATON_DEFAULT_IN_4_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(4, data_in_5, LL_ATON_DEFAULT_IN_5_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(5, data_in_6, LL_ATON_DEFAULT_IN_6_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(6, data_in_7, LL_ATON_DEFAULT_IN_7_SIZE_BYTES);
#endif   /* USER_ALLOCATED_INPUTS == 7 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 8)
LL_ATON_Set_User_Input_Buffer_Default(0, data_in_1, LL_ATON_DEFAULT_IN_1_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(1, data_in_2, LL_ATON_DEFAULT_IN_2_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(2, data_in_3, LL_ATON_DEFAULT_IN_3_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(3, data_in_4, LL_ATON_DEFAULT_IN_4_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(4, data_in_5, LL_ATON_DEFAULT_IN_5_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(5, data_in_6, LL_ATON_DEFAULT_IN_6_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(6, data_in_7, LL_ATON_DEFAULT_IN_7_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(7, data_in_8, LL_ATON_DEFAULT_IN_8_SIZE_BYTES);
#endif   /* USER_ALLOCATED_INPUTS == 8 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 9)
LL_ATON_Set_User_Input_Buffer_Default(0, data_in_1, LL_ATON_DEFAULT_IN_1_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(1, data_in_2, LL_ATON_DEFAULT_IN_2_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(2, data_in_3, LL_ATON_DEFAULT_IN_3_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(3, data_in_4, LL_ATON_DEFAULT_IN_4_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(4, data_in_5, LL_ATON_DEFAULT_IN_5_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(5, data_in_6, LL_ATON_DEFAULT_IN_6_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(6, data_in_7, LL_ATON_DEFAULT_IN_7_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(7, data_in_8, LL_ATON_DEFAULT_IN_8_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(8, data_in_9, LL_ATON_DEFAULT_IN_9_SIZE_BYTES);
#endif   /* USER_ALLOCATED_INPUTS == 9 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS == 10)
LL_ATON_Set_User_Input_Buffer_Default(0, data_in_1, LL_ATON_DEFAULT_IN_1_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(1, data_in_2, LL_ATON_DEFAULT_IN_2_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(2, data_in_3, LL_ATON_DEFAULT_IN_3_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(3, data_in_4, LL_ATON_DEFAULT_IN_4_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(4, data_in_5, LL_ATON_DEFAULT_IN_5_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(5, data_in_6, LL_ATON_DEFAULT_IN_6_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(6, data_in_7, LL_ATON_DEFAULT_IN_7_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(7, data_in_8, LL_ATON_DEFAULT_IN_8_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(8, data_in_9, LL_ATON_DEFAULT_IN_9_SIZE_BYTES);
LL_ATON_Set_User_Input_Buffer_Default(9, data_in_10, LL_ATON_DEFAULT_IN_10_SIZE_BYTES);
#endif   /* USER_ALLOCATED_INPUTS == 10 */
#endif   /* LL_ATON_DEFAULT_USER_ALLOCATED_INPUTS */
}
void connect_output_buffers(void)
{
#if (defined(LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS) && (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS > 0))
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 1)
LL_ATON_Set_User_Output_Buffer_Default(0, data_out_1, LL_ATON_DEFAULT_OUT_1_SIZE_BYTES);
#endif   /* USER_ALLOCATED_OUTPUTS == 1 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 2)
LL_ATON_Set_User_Output_Buffer_Default(0, data_out_1, LL_ATON_DEFAULT_OUT_1_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(1, data_out_2, LL_ATON_DEFAULT_OUT_2_SIZE_BYTES);
#endif   /* USER_ALLOCATED_OUTPUTS == 2 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 3)
LL_ATON_Set_User_Output_Buffer_Default(0, data_out_1, LL_ATON_DEFAULT_OUT_1_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(1, data_out_2, LL_ATON_DEFAULT_OUT_2_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(2, data_out_3, LL_ATON_DEFAULT_OUT_3_SIZE_BYTES);
#endif   /* USER_ALLOCATED_OUTPUTS == 3 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 4)
LL_ATON_Set_User_Output_Buffer_Default(0, data_out_1, LL_ATON_DEFAULT_OUT_1_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(1, data_out_2, LL_ATON_DEFAULT_OUT_2_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(2, data_out_3, LL_ATON_DEFAULT_OUT_3_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(3, data_out_4, LL_ATON_DEFAULT_OUT_4_SIZE_BYTES);
#endif   /* USER_ALLOCATED_OUTPUTS == 4 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 5)
LL_ATON_Set_User_Output_Buffer_Default(0, data_out_1, LL_ATON_DEFAULT_OUT_1_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(1, data_out_2, LL_ATON_DEFAULT_OUT_2_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(2, data_out_3, LL_ATON_DEFAULT_OUT_3_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(3, data_out_4, LL_ATON_DEFAULT_OUT_4_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(4, data_out_5, LL_ATON_DEFAULT_OUT_5_SIZE_BYTES);
#endif   /* USER_ALLOCATED_OUTPUTS == 5 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 6)
LL_ATON_Set_User_Output_Buffer_Default(0, data_out_1, LL_ATON_DEFAULT_OUT_1_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(1, data_out_2, LL_ATON_DEFAULT_OUT_2_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(2, data_out_3, LL_ATON_DEFAULT_OUT_3_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(3, data_out_4, LL_ATON_DEFAULT_OUT_4_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(4, data_out_5, LL_ATON_DEFAULT_OUT_5_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(5, data_out_6, LL_ATON_DEFAULT_OUT_6_SIZE_BYTES);
#endif   /* USER_ALLOCATED_OUTPUTS == 6 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 7)
LL_ATON_Set_User_Output_Buffer_Default(0, data_out_1, LL_ATON_DEFAULT_OUT_1_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(1, data_out_2, LL_ATON_DEFAULT_OUT_2_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(2, data_out_3, LL_ATON_DEFAULT_OUT_3_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(3, data_out_4, LL_ATON_DEFAULT_OUT_4_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(4, data_out_5, LL_ATON_DEFAULT_OUT_5_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(5, data_out_6, LL_ATON_DEFAULT_OUT_6_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(6, data_out_7, LL_ATON_DEFAULT_OUT_7_SIZE_BYTES);
#endif   /* USER_ALLOCATED_OUTPUTS == 7 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 8)
LL_ATON_Set_User_Output_Buffer_Default(0, data_out_1, LL_ATON_DEFAULT_OUT_1_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(1, data_out_2, LL_ATON_DEFAULT_OUT_2_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(2, data_out_3, LL_ATON_DEFAULT_OUT_3_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(3, data_out_4, LL_ATON_DEFAULT_OUT_4_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(4, data_out_5, LL_ATON_DEFAULT_OUT_5_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(5, data_out_6, LL_ATON_DEFAULT_OUT_6_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(6, data_out_7, LL_ATON_DEFAULT_OUT_7_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(7, data_out_8, LL_ATON_DEFAULT_OUT_8_SIZE_BYTES);
#endif   /* USER_ALLOCATED_OUTPUTS == 8 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 9)
LL_ATON_Set_User_Output_Buffer_Default(0, data_out_1, LL_ATON_DEFAULT_OUT_1_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(1, data_out_2, LL_ATON_DEFAULT_OUT_2_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(2, data_out_3, LL_ATON_DEFAULT_OUT_3_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(3, data_out_4, LL_ATON_DEFAULT_OUT_4_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(4, data_out_5, LL_ATON_DEFAULT_OUT_5_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(5, data_out_6, LL_ATON_DEFAULT_OUT_6_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(6, data_out_7, LL_ATON_DEFAULT_OUT_7_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(7, data_out_8, LL_ATON_DEFAULT_OUT_8_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(8, data_out_9, LL_ATON_DEFAULT_OUT_9_SIZE_BYTES);
#endif   /* USER_ALLOCATED_OUTPUTS == 9 */
#if (LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS == 10)
LL_ATON_Set_User_Output_Buffer_Default(0, data_out_1, LL_ATON_DEFAULT_OUT_1_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(1, data_out_2, LL_ATON_DEFAULT_OUT_2_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(2, data_out_3, LL_ATON_DEFAULT_OUT_3_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(3, data_out_4, LL_ATON_DEFAULT_OUT_4_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(4, data_out_5, LL_ATON_DEFAULT_OUT_5_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(5, data_out_6, LL_ATON_DEFAULT_OUT_6_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(6, data_out_7, LL_ATON_DEFAULT_OUT_7_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(7, data_out_8, LL_ATON_DEFAULT_OUT_8_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(8, data_out_9, LL_ATON_DEFAULT_OUT_9_SIZE_BYTES);
LL_ATON_Set_User_Output_Buffer_Default(9, data_out_10, LL_ATON_DEFAULT_OUT_10_SIZE_BYTES);
#endif   /* USER_ALLOCATED_OUTPUTS == 10 */
#endif   /* LL_ATON_DEFAULT_USER_ALLOCATED_OUTPUTS */
}