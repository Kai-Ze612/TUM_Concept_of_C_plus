# Sheet 01 - Project Setup with CMake

## Create .cpp file
```
nano main.cpp
```
Write the c++ program

## Create CMakeLists.txt
```
nano CMakeLists.txt
```
```
 cmake_minimum_required(VERSION 3.10)
   project(HelloWorldProject)

   # Set the C++ standard
   set(CMAKE_CXX_STANDARD 17)
   set(CMAKE_CXX_STANDARD_REQUIRED True)

   # Add the executable
   add_executable(helloworld main.cpp)
```

## Build the project
* Create a build foler `mkdir build`
* `cd build`
* `cmake ..`
* `make`
* This will generate an executable named `helloworld` in the `build` directory.

## Execute the cpp file
`./helloworld`
`./helloworld John`

## run eval.sh file
* build docker image `docker build -t your-image-name .`
* run assessment.sh ` docker run --rm -v $PWD/:/homework <image-name> /homework/assessment.sh`

