# A Toy Game Engine

#### Features

* GLFW + GLAD + ImGui for window creation and editor UI
* Log system —— spdlog 
* Main Game Loop, Event System & Input System
* 2D Render API : Simple OpenGL Abstraction, can draw triangle and quad with custom shader, (sub)textures, support batch rendering (use glm for maths related)
* ECS —— entt  
* Native Script Support
* Visual profile (generate json file that can be open with chrome://tracing)
* Simple Particle System

#### Main Features to come : 

* 2D Editor UI
* Lua support (even lox support) —— sol3
* Simple 2D collision
* Memory allocation, smart pointer

#### Build Guide

clone the repo and run Win-GenerateProject.bat under the scripts folder (only supports vs2017/2019 now)

