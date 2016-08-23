@echo off

set vcvarsall="C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat"
call %vcvarsall% x86

if not exist "build" mkdir build
pushd build
cl /DVR_API_EXPORT /LD ..\openvr.cpp /Fe:openvr_api.dll
popd
