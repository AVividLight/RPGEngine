# RPGEngine

## Table of Contents

## Overview

## Build Instructions

Simply use CMake to configure and generate, then navigate to the build directory and run `cmake --build .`.

## Development Tips

It is recommended that you add the following to your VSCode include path in order to configure intelisense for 3rd party libraries (note, you will have to provide the path to your build directory):

```plaintext
~path_to_build~/_deps/sdl2-src/include/**
~path_to_build~/_deps/sdl_image-src/**
~path_to_build~/_deps/sdl_ttf-src/**
~path_to_build~/_deps/nlohmann_json-src/include/**
```

## Licenses

RPGEngine uses the following open source resources:

* [SDL_FontCache](https://github.com/grimfang4/SDL_FontCache) which is licensed under the MIT license
* [ChivoMono-Regular](https://github.com/Omnibus-Type/Chivo) which is licensed under OFL 1.1
