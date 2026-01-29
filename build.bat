@echo off
echo Setting up SFML project...

REM Copy SFML DLLs to Debug folder
xcopy /y External\SFML\bin\*.dll CalculatorSFML\bin\Debug\

REM Open the solution
start CalculatorSFML.sln

echo Done!
pause