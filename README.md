# Raycasting Maze Engine

A C-based real-time raycasting engine that renders a pseudo-3D world from a 2D grid map using a frame-based rendering loop and DDA-based raycasting. Built with MiniLibX and X11 (XQuartz on macOS).

---
## Demo

![demo](assets/demo.gif)

---
## Overview

This project is a lightweight raycasting engine inspired by early 3D games such as Wolfenstein 3D.

It transforms a 2D grid-based map into a real-time pseudo-3D rendering using raycasting.

The goal of this project is not only to implement raycasting, but also to understand low-level graphics systems, event-driven architecture, and OS-dependent rendering pipelines.

## Key Features

- Raycasting-based pseudo-3D rendering
- DDA (Digital Differential Analyzer) algorithm for fast grid traversal
- Frame-based rendering loop (game loop architecture)
- Real-time keyboard input handling
- Collision detection system
- Map parsing and strict validation
- X11-based rendering via MiniLibX

---

## Architecture

This project is built on a classic graphics stack that relies on X11 on Unix-like systems.

### Rendering Pipeline

```
Input Events (Keyboard)
↓
Game State Update
↓
Frame Loop (mlx_loop)
↓
Raycasting Engine (DDA)
↓
MiniLibX Rendering Layer
↓
X Server (XQuartz / Xorg)
↓
Window Display
```

On macOS, XQuartz is required to provide the X11 server environment.

---

## Technical Details

### Rendering Model

The engine uses a frame-based rendering loop.

Each frame consists of:

1. Input processing (event-driven)
2. State update (player movement, direction)
3. Full scene re-render using raycasting
4. Display update via MiniLibX

This design ensures deterministic frame updates and avoids partial rendering artifacts.

### Raycasting Algorithm (DDA)

The rendering engine is based on a classic raycasting approach using the Digital Differential Analyzer (DDA) algorithm.

Each frame, rays are cast from the player's position into the 2D map grid to detect wall intersections efficiently.

The DDA algorithm allows stepping through the grid cell-by-cell instead of performing continuous ray intersection calculations, significantly improving performance.

This approach is widely used in early 3D engines such as Wolfenstein 3D.

## Map System

The map is represented as a 2D grid loaded from a `.ber` file.

### Validation Rules:

- Map must be rectangular
- Must be fully enclosed by walls
- Must contain:
  - One player start position
  - At least one exit
  - At least one collectible

### Path Validation:

A flood-fill algorithm is used to ensure:

- All collectibles are reachable
- Exit is reachable from player spawn


## Constraints

This project was implemented under strict constraints:

- No external game engines
- Minimal graphics abstraction (MiniLibX only)
- Direct interaction with X11 system
- Manual memory management in C
- Platform-dependent graphics stack

## Platform Dependencies

This project depends on system-level graphics infrastructure:

- X11 (Linux)
- XQuartz (macOS)

As a result, the build and runtime behavior may vary depending on:

- OS (Linux / macOS)
- Compiler version (Clang vs GCC)
- Library paths
- X11 runtime availability

## Key Learnings

This project provided hands-on experience with:

- Low-level graphics pipeline (X11-based rendering)
- Event-driven architecture in real-time systems
- Frame-based rendering loops (game loop design)
- System-level dependency management
- Cross-platform build issues (macOS vs Linux)
- C memory management in performance-critical systems

## Future Improvements

### 1. Containerized Development Environment

To eliminate OS and dependency issues, the project will be containerized using Docker.

This will enable:

- Reproducible builds across platforms
- Consistent X11 or virtual display environments
- Simplified setup for contributors

---

### 2. OS-Independent Rendering Backend

Future versions may replace X11/MiniLibX with:

- SDL2
- GLFW + OpenGL
- Web-based rendering (WebGL / Canvas / WebAssembly)

---

### 3. Web-Based Visualization (Experimental)

A long-term direction is migration to browser-based rendering:

- Rendering via WebGL or Canvas
- Game logic compiled to WebAssembly
- Fully OS-independent execution environment
