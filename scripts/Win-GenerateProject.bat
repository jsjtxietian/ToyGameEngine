@echo off
pushd %~dp0\..\
call vendor\premake\bin\premake5.exe vs2022
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
msbuild ToyEngine.sln -target:CSharpEngine
msbuild QAQNut\SandboxProject\Assets\Scripts\Sandbox.sln -target:Sandbox
msbuild ToyEngine.sln -target:QAQNut
popd
@REM PAUSE