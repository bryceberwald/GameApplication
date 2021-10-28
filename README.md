﻿# Game Application using the Raylib C++ Gaming Library
 
 For Mac OS Users you can download raylib via homebrew
```bash
brew install raylib
```

Compiling on Windows OS

  1. Open Terminal
  2. Navigate into the directory with the CMake file
  3. Copy & Paste the cmd below to compile on Windows

```bash
mingw32-make
```
# Raylib Basic Window

```cpp
#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
```
