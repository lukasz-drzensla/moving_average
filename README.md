# moving_average
Simple library for implementing moving average on a microcontroller. No dynamic memory allocation. Capable of creating multiple independent average counters. The type of the variables used to calculate the average (eg int, float) is defined by the user of the library.

The library consists of 3 files: moving_average.h, moving_average.c and user_def.h. This repository provides an example project showing how the library can be used. To build the example project use command line to cd to the build_* directory (* - your OS) and enter the following command: "cmake ..". Then you can use your IDE or "make" to build the project.

The file moving_average.h contains declarations of functions and structures, moving_average.c contains their definitions.
user_def.h contains type definition and definition of maximum capacity of averaging buffer.
