# Node-Based Image Editor (C++/Qt + OpenCV)

This is a fully interactive visual node-based image manipulation tool.

## Features
- Qt-based node graph editor with draggable nodes and visual connections
- 10 processing nodes including:
  - Image Input, Output
  - Brightness/Contrast
  - Color Channel Split
  - Blur, Threshold
  - Edge Detection (Sobel/Canny)
  - Blend Modes
  - Noise Generation
  - Convolution Kernel
- Real-time image processing pipeline execution
- Preview and save output

## Build Instructions
```bash
mkdir build && cd build
cmake ..
cmake --build .
./NodeImageEditor
```

## Dependencies
- Qt 6.x (Widgets)
- OpenCV 4.x
