# My3DEngine
A 3D graphics engine built in C++ for rendering a physics and astronomy-themed solar system, created as part of my portfolio for the NUS Computer Science scholarship.

## Overview
This project uses OpenGL, GLFW, GLAD, and GLM to create a 3D rendering engine. The goal is to simulate a solar system with planets and orbits, demonstrating my skills in C++, graphics programming, and physics.


## Milestone 1: Window Creation
- Created an 800 x 600 OpenGL window using GLFW and GLAD
- Fixed "too many inializer values" and "class Window has no members" by correcting 'Renderer.h".
- Resolved GLAD header conflict and build issues to generate 'My3DEngine.exe' .
- Window opens and closes on ESC key presses.

## Build instructions 
1. Clone the repository: 'git clone<repeository-url>'
2. Navigate to the project directory: 'cd My3DEngine'
3. Create a build directory: 'mkdir build && cd build'
4. Run CMake: 'cmake ..'
5. Build the project: 'cmake --build . --config Release'
6. Run the executable: 'bin\My3DEngine.exe'

##Dependencies 
- GLFW 3.4 
- GLAD
- GLM
- OpenGL

## Future Work
- Milestone 2 : Render a 3D sphere to represent a planet
- Milestone 3 : Simulate a planetary orbits with physics-based motion.