@echo off
echo ==========================================
echo      Neon Flow - Build Verification
echo ==========================================

WHERE cmake >nul 2>nul
IF %ERRORLEVEL% NEQ 0 (
    IF EXIST "C:\Program Files\CMake\bin\cmake.exe" (
        echo [INFO] Found CMake in Program Files. Adding to PATH...
        SET "PATH=%PATH%;C:\Program Files\CMake\bin"
    ) ELSE (
        echo [ERROR] cmake not found in PATH or standard locations.
        echo Please run this script from a terminal with cmake/compiler available.
        echo (e.g., Visual Studio Developer Command Prompt)
        pause
        exit /b 1
    )
)

echo [1/3] Generating Project Files...
cmake -S . -B Build
IF %ERRORLEVEL% NEQ 0 GOTO ERROR

echo [2/3] Building...
cmake --build Build --config Release
IF %ERRORLEVEL% NEQ 0 GOTO ERROR

echo [3/3] Running Performance Test...
Build\Core\Release\TestPerformance.exe

echo.
echo [4/3] Starting Visual Preview (Close window to stop)...
Build\Core\Release\TestVisual.exe

IF %ERRORLEVEL% NEQ 0 (
    REM Try checking Debug folder
    if exist Build\Core\Debug\TestVisual.exe (
        Build\Core\Debug\TestVisual.exe
    )
)

echo.
echo ==========================================
echo             VERIFICATION COMPLETE
echo ==========================================
pause
exit /b 0

:ERROR
echo [FAILED] Build or Generation failed.
pause
exit /b 1
