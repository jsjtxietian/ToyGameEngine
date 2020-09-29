# A Toy Game Engine

#### Features

* GLFW + GLAD + ImGui for window creation and editor UI
* Log system with spdlog 
* Main Game Loop, Event System & Input System
* 2D Render API, which is a simple abstraction of OpenGL ,currently can draw sprite with custom shader, (sub)textures, and support batch rendering
* ECS with entt, still try to add more components: tag, transform, spriterenderer, native script
* Visual profile (generate json file that can be open with chrome://tracing)
* Simple Particle System

#### Main Features to come : 

* 2D Editor UI (current working on)
* Lua support with sol3, or even lox support
* Simple 2D collision
* Memory allocation, smart pointer

#### Build Guide

clone the repo and run Win-GenerateProject.bat under the scripts folder (only supports vs2017/2019 now)

#### Reference

* https://github.com/TheCherno/Hazel
* https://github.com/OneLoneCoder/olcPixelGameEngine

