
:: List of folders to copy
set folders="shaders"

:: Target directories
set target1=./x64/Debug/
set target2=./x64/Release/

:: Ensure target directories exist
if not exist "%target1%" mkdir -p "%target1%"
if not exist "%target2%" mkdir -p "%target2%"

:: Loop through each folder
for %%f in (%folders%) do (
    echo Copying %%f to %target1%
    robocopy "%%f" "%target1%%%~nxf" /mir /xo /r:3 /w:1

    echo Copying %%f to %target2%
    robocopy "%%f" "%target2%%%~nxf" /mir /xo /r:3 /w:1
)

:: Finished
echo All folders have been copied.
