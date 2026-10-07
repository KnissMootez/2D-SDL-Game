# 2D SDL Game: C++ and SDL2

A small 2D game written in **C++** with **SDL2**, built from scratch, with no game engine, to practice object-oriented design and the core of a game loop.

<!-- screenshots coming soon -->

## What it does

- A 600×590 window with a forest background, rendered at a fixed **30 FPS**
- A main menu with **Play / Settings / Quit** buttons that switch to a highlighted texture on hover
- A working **Quit** button that pushes an `SDL_QUIT` event
- Two animated sprites (a Smurf and Azrael the cat) moving across the screen

## Code structure

| Class | Role |
|---|---|
| `Game` | Owns the window and renderer; runs `init → handleEvents → update → render → clean` |
| `TextureManager` | Static helper that loads PNGs into `SDL_Texture`s (SDL2_image) |
| `GameObject` | A textured, positioned sprite with `Update()` and `Render()` |
| `Button` | Extends `GameObject` with hover and click detection (`SDL_PointInRect`) and texture swapping |
| `Vector2D` | 2D vector with overloaded `+`, `-`, `*` operators |

`main.cpp` implements a classic **fixed-timestep game loop**: it measures each frame with `SDL_GetTicks()` and sleeps the remainder of the 33 ms budget.

**OOP concepts used:** classes and encapsulation, inheritance (`Button` → `GameObject` → `TextureManager`), constructor initializer lists, static member functions and operator overloading.

## Build (Windows, Visual Studio 2022)

1. Download the development libraries from the official SDL releases:
   - [SDL2](https://github.com/libsdl-org/SDL/releases) (VC) → `C:\Dev\SDL2`
   - [SDL2_image](https://github.com/libsdl-org/SDL_image/releases) (VC) → `C:\Dev\SDL2_image-2.0.1`
   - SDL_mixer (VC) → `C:\Dev\SDL_mixer-1.2.7`

   These are the paths the project expects; edit them in *Project → Properties → VC++ Directories* if yours differ.
2. Open `BirchEngine.sln`, select **x64**, and build.
3. Copy `SDL2.dll`, `SDL2_image.dll` and its image-format DLLs (from the `lib\x64` folders) next to the executable, or into `BirchEngine/` to run from Visual Studio.

## What I'd improve next

- Load each button texture once and swap pointers, instead of reloading from disk on every mouse move
- Process all pending events per frame (`while (SDL_PollEvent(...))`) and handle clicks on `SDL_MOUSEBUTTONDOWN`
- Free textures and objects in `clean()`, and destroy the renderer before the window
- Prefer composition over inheritance for `GameObject` / `TextureManager`
- Add player input, collision detection and scoring to turn the demo into a game

## Credits & disclaimer

- The project skeleton is based on the **BirchEngine** starter template from Carl Birch's *"How to make a game in C++ & SDL2"* tutorial series.
- **This is a non-commercial learning project.** The Smurfs (© Peyo / IMPS) and Azrael are the property of their respective owners. No rights are claimed, and no money is made from this project. If you are a rights holder and want the assets removed, please open an issue.
