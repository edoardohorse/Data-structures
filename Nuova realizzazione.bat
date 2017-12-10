@echo off
setlocal enableDelayedExpansion
set name=%1

set "header=%name%.h"
set "header_test=%name%_for_test.h"
set "header_testcpp=test_%name%.cpp"



REM echo !header!
REM echo !header_test!
REM echo !header_testcpp!

echo. 2> !header!
cd tests
echo. 2> !header_test!
echo. 2> !header_testcpp!
cd ..