# compile_scheduler
Master thesis work on solving [Google Hash Code 2019 Challenge Solution - Compiling Google](https://codingcompetitions.withgoogle.com/hashcode/round/00000000000501c5)

Problem: [PDF](https://codejam.googleapis.com/dashboard/get_file/AQj_6U0OoR-xOxOTj-X4RKJZzl9rHXOw8UVBeUkU9ACCE1YIaD_gDZSTtRbLHubZr1gNTHLZOkIniTmhwWbaZ2hROJbTMQZA430d/hashcode_2019_final_round.pdf?dl=1)

Dataset: [Source](https://codejam.googleapis.com/dashboard/get_file/AQj_6U2mIz2zq0O7JoCYvB4nguaAEJe_h14nrZ09Iw5feU1BOOjy0O9JSUAdEPKjsr1fJ6Nmehl-rVXp46VKMq1ZoAGok3eVsxZi/hashcode_2019_final_round.zip?dl=1)
  * Datasets are already dowloaded in project repo and live in `/data` folder

## Prerequisites

  * C++ compiler (e.g. GCC or Clang)
    * macOS: `brew install gcc`
  * CMake
    * macOS: `brew install cmake`


## Build

  * Run this first time and whenever changing `CMakeLists.txt`: `cmake -B cmake-build-debug`
  * Build code: `cmake --build cmake-build-debug`

## Run
  `./cmake-build-debug/compile_scheduler data/a_example.in`

All possible input datas are listed in `/data` folder:

  * `a_example.in`
  * `b_narrow.in`
  * `c_urgent.in`
  * `d_typical.in`
  * `e_intriguing.in`
  * `f_big.in`
