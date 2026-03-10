*This project has been written by akaung from the 42 cursus*
# Fractol - Fractal Renderer

A C program that renders the Mandelbrot and Julia fractals using the MiniLibX graphics library.

## Features

- **Mandelbrot Set** - Classic fractal rendering
- **Julia Set** - Dynamic Julia fractals with customizable parameters
- **Interactive Controls**:
  - Mouse scroll to zoom in/out
  - `C` key to randomize colors
  - `ESC` key to close the program
- **Color Randomization** - Press C to cycle through different color schemes
- **Smooth Iteration** - High iteration count (1024) for better detail and smoothness
- **Vibrant Gradients** - Enhanced color palettes for better visuals

## Building

```bash
make
```

The project uses a Makefile to compile all source files and link with the MiniLibX library.

## Usage

### Mandelbrot Set
```bash
./fractol mandelbrot
```

### Julia Set
```bash
./fractol julia <cr> <ci>
```

Where:
- `<cr>` - Real component of the Julia set parameter (e.g., -0.7)
- `<ci>` - Imaginary component of the Julia set parameter (e.g., 0.27015)

Example:
```bash
./fractol julia -0.7 0.27015 # for cool julia
./fractol julia -0.8 0.156 # for cooler cloud julia
```

## Controls

| Key | Action |
|-----|--------|
| `Mouse Scroll` | Zoom in/out |
| `C` | Randomize colors |
| `ESC` | Close the program |

## Project Structure

```
.
├── Makefile
├── README.md
├── includes/
│   └── fractol.h          # Header file with structures and function declarations
├── src/
│   ├── main.c             # Entry point with argument parsing
│   ├── init.c             # Initialization of fractal structures
│   ├── draw.c             # Screen drawing utilities
│   ├── mandelbrot.c       # Mandelbrot set calculation and rendering
│   ├── julia.c            # Julia set calculation and rendering
│   ├── events.c           # Event handling (keyboard, mouse)
│   ├── mouse.c            # Mouse interaction (zoom/pan)
│   └── utils.c            # Utility functions (color interpolation, etc.)
└── mlx/                   # MiniLibX graphics library
```

## Implementation Details

### Constants
- **MAX_ITER**: 1024 - Maximum iterations for fractal calculation
- **WIDTH**: 800 pixels
- **HEIGHT**: 600 pixels

### Color System
The program uses a smooth color gradient system:
1. Dark Blue → Cyan (0% - 25%)
2. Cyan → Lime (25% - 50%)
3. Lime → Orange (50% - 75%)
4. Orange → White (75% - 100%)

Colors can be randomized by pressing the `C` key, which multiplies each channel by a random factor.

### Algorithms
- **Smooth Iteration**: Uses logarithmic escape-time algorithm for smooth color transitions
- **Complex Arithmetic**: Efficient complex number calculations for both Mandelbrot and Julia sets

## Compilation Flags

The project uses the following compilation flags:
- `-Wall` - Enable all warnings
- `-Wextra` - Enable extra warnings
- `-Werror` - Treat warnings as errors
- `-O2` - Optimization level 2

## Error Handling

The program validates command-line arguments and displays usage information:
```
Usage: ./fractol mandelbrot
Usage: ./fractol julia <cr> <ci>
```

