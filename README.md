# Raycasting 3D Maze

## Overview

This project is a first-person pseudo-3D maze built in C using MiniLibX and X11.

It implements a complete rendering pipeline that transforms a 2D grid map into a real-time first-person projection using raycasting and grid-based collision logic.

## Key Features

- Frame-based rendering loop (game loop)
- Event-driven input system
- Raycasting and grid-based collision detection
- Strict map validation system
- X11-based rendering via MiniLibX

## Usage

### Build and Run

```sh
git clone https://github.com/takato7/raycasting-maze.git
cd raycasting-maze
make
./cub3D maps/config.cub
```

### Clean up object files

```sh
make clean
```

Remove the program too:

```sh
make fclean
```

### Movement & Camera

- W / A / S / D : Move (forward / left / backward / right)
- ← / → : Rotate view
- Mouse : Rotate view (when window is focused)

### Interaction

- SPACE : Open / close door

### UI

- M : Toggle minimap
- F : Toggle FPS counter

### View Settings

- Numpad * / Numpad / : Increase / decrease FOV (Field of View)
- Numpad + / Numpad - : Increase / decrease mouse sensitivity
- Numpad 0 : Reset mouse sensitivity to default

### System

- ESC : Quit program

## Architecture

The engine is built around a **frame-based game loop architecture** with a clear separation between input handling, state update, and rendering as follows: 

- Input layer → updates only state
- Engine layer → computes raycasting and collisions
- Rendering layer → draws full frame from state

```
Input Events (Keyboard / Mouse)
        ↓
Game State Update
        ↓
Raycasting Engine
        ↓
Frame Renderer
        ↓
MiniLibX
        ↓
X11 Server (XQuartz / Xorg)
        ↓
Display Output
```

Rendering is decoupled from input events and handled exclusively inside the main frame loop.

## Raycasting Algorithm

The rendering pipeline is based on column-wise ray projection.

For each screen column:

1. A ray is cast from the player position
2. DDA-based grid traversal determines the first wall cell intersected by the ray
3. Perpendicular wall distance is computed
4. Projected wall height is calculated
5. A vertical textured stripe is rendered

## Map System

The engine loads a scene description file with the `.cub` extension.

The file contains rendering configuration and a grid-based map used for raycasting.

### File Structure

A `.cub` file consists of two parts:

1. Configuration section (textures, colors)
2. Map section (must be the last element)

### Configuration Elements

Each element starts with a type identifier followed by its parameters.

#### Textures

- NO  : North wall texture
- SO  : South wall texture
- WE  : West wall texture
- EA  : East wall texture
- DO  : Door texture
- DOS : Door side texture
- SQ0 ~ SQ3 : Sprite animation frames

#### Colors

- F : Floor color (R,G,B)
- C : Ceiling color (R,G,B)

### Map Format

The map must:

- Be composed of valid characters only:
  - `0`          : Empty space
  - `1`          : Wall
  - `N, S, E, W` : Player spawn + orientation
  - `C`          : Sprite
  - `D`          : Door
- Be fully enclosed by walls
- Contain exactly one player spawn
- Be the last element in the file

### Parsing Rules

- Elements can be separated by one or more empty lines
- Order of configuration elements is not fixed
- Spaces are valid within the map and must be handled correctly
- The map is parsed exactly as written in the file

If any misconfiguration is detected, the program must exit cleanly

### Example

```
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm

DO ./textures/door_front.xpm
DOS ./textures/door_side.xpm

SQ0 ./textures/sprite_0.xpm
SQ1 ./textures/sprite_1.xpm
SQ2 ./textures/sprite_2.xpm
SQ3 ./textures/sprite_3.xpm

F 70,8,8
C 40,40,40

111111111
1000C0001
10D000001
1000N0001
111111111
```

## Constraints

This project was implemented under strict constraints:

- No external game engines
- Minimal graphics abstraction (MiniLibX only)
- Direct interaction with X11 system
- Manual memory management in C
- Platform-dependent graphics stack

## Platform Dependencies

This project depends on X11 for rendering:

- Linux: Xorg
- macOS: XQuartz

As a result, the build and runtime behavior may vary depending on:

- OS (Linux / macOS)
- Compiler version (Clang vs GCC)
- Library paths
- X11 runtime availability

## License

It uses [MiniLibX](https://qst0.github.io/ft_libgfx/man_mlx.html), which is distributed under the BSD 2-Clause License.

## References

- [Wolfenstein 3D](http://users.atw.hu/wolf3d/)
- [Raycasting tutorial by Lode Vandevenne](https://lodev.org/cgtutor/raycasting.html)
- [42 Docs MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)

## Key Learnings

This project provided hands-on experience with:

- Low-level graphics pipeline (X11-based rendering)
- Event-driven architecture in real-time systems
- Frame-based rendering loops (game loop design)
- Cross-platform build issues (macOS vs Linux)
- C memory management in performance-critical systems

## Future Improvements

### 1. Containerized Development Environment

To eliminate OS and dependency issues, the project will be containerized using Docker.

This will enable:

- Reproducible builds across platforms
- Consistent X11 or virtual display environments
- Simplified setup for contributors

### 2. OS-Independent Rendering Backend

Future versions may replace X11/MiniLibX with:

- SDL2
- GLFW + OpenGL
- Web-based rendering (WebGL / Canvas / WebAssembly)

### 3. Web-Based Visualization (Experimental)

A long-term direction is migration to browser-based rendering:

- Rendering via WebGL or Canvas
- Game logic compiled to WebAssembly
- Fully OS-independent execution environment
