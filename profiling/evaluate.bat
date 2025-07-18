@echo off
REM Check if a parameter was provided
IF "%~1"=="" (
    echo Usage: %~nx0 ^<model_name^>
    exit /b 1
)

REM Set model name from first argument
set "MODEL_NAME=%~1"

REM Get file name without extension
for %%F in ("%MODEL_NAME%") do set "BASE_NAME=%%~nF"

REM Get current timestamp in format YYYYMMDD_HHMMSS
for /f "tokens=1-3 delims=/- " %%a in ("%date%") do (
    set "YYYY=%%c"
    set "MM=%%a"
    set "DD=%%b"
)
for /f "tokens=1-2 delims=:." %%a in ("%time%") do (
    set "HH=%%a"
    set "MIN=%%b"
)
set "OUTPUT_DIR=%BASE_NAME%_output_%YYYY%%MM%%DD%_%HH%%MIN%00"

REM Create the output directory
REM if not exist "%OUTPUT_DIR%" (
REM    mkdir "%OUTPUT_DIR%"
REM )

REM Run stedgeai generate
stedgeai generate -m "%MODEL_NAME%" --target stm32n6 --st-neural-art profile-allmems--O3

REM Run the Python loader
python "%STEDGEAI_CORE_DIR%\scripts\N6_scripts\n6_loader.py" --n6-loader-config "./config_files/windows/config_n6l.json"

REM Optionally, run validate (commented out in original)
REM stedgeai validate -m "%MODEL_NAME%" --target stm32 --mode -d /dev/tty

REM Set PYTHONPATH
set "PYTHONPATH=%STEDGEAI_CORE_DIR%\scripts\ai_runner;%PYTHONPATH%"

REM Run the checker
python "%STEDGEAI_CORE_DIR%\scripts\ai_runner\examples\checker.py" -d serial:COM4:921600 -b 10
