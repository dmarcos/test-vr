@echo off

set vcvarsall="C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat"
call %vcvarsall x86

# Build openvr DLL
pushd ..\
call build
popd

# Build example
mkdir build
pushd build
cl ..\main.cpp
popd
