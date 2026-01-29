@echo off
echo Setting up SFML project...

REM Copy SFML DLLs to Debug folder
xcopy /y External\SFML-3.0.2\bin\*.dll bin\x64\Debug\

REM Open the solution
start CalculatorSFML.sln

echo Done! Closing in 5 seconds...
timeout /t 3 /nobreak >nul
exit