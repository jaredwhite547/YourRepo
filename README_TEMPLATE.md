<p align="center"><img width="45%" src="CoolLogo.png"></p>
(You need to update the below URL in the markdown file to point at your repository)

[![Run Tests](https://github.com/7thfleet/CMake_Example/actions/workflows/main.yml/badge.svg)](https://github.com/7thfleet/CMake_Example/actions/workflows/main.yml)

# MathUtils
(A tldr of your project. Something like:)  
### MathUtils is a cross platform CC0 C++14 application & library for generating the dot product of `std::vector`.

# Table of Contents
1. [Introduction](#introduction)
2. [Dependencies](#dependencies)
3. [Building & Testing](#building_testing)
    1. [On Boise State's R2](#building_testing_on_r2)
    2. [On a normal machine](#building_testing_on_a_normal_machine)
4. [Running](#running)
5. [Libraries Used](#libraries_used)
6. [Contributors](#contributors)

<a name="introduction"></a>
# Introduction
(A longer description of your awesome project!)
MathUtils is a simple library and application to show basic CMake functionality.

<a name="dependencies"></a>
# Dependencies
* CMake 3.14 or newer
* A C++14 capable compiler
* An internet connection (some dependencies are fetched at build time via CMake's `FetchContent`

<a name="building_testing"></a>
# Building & Testing
<a name="building_testing_on_r2"></a>
## On Boise State's R2
Load the the required modules:  
```module load cmake gcc```  
Follow the steps for [on a normal machine](#building_testing_on_a_normal_machine)

<a name="building_testing_on_a_normal_machine"></a>
## On a normal machine
1. ### Clone the repository:   
(@@TODO Change)  
```
git clone git@github.com:7thfleet/CMake_Example.git
```

2. ### `cd` into the directory:  
(@@TODO Change)  
```
cd CMake_Example
```

3. ### Generate the build files:  
```
cmake -S . -B build
```

   - The default build type is Debug. To change it for single-configuration generators (everything **but** Xcode and Visual Studio), append the following to the `cmake -S . -B build` command:  
``` -DCMAKE_BUILD_TYPE=BUILD_TYPE```  
Where `BUILD_TYPE` is `Debug`, `Release`, `RelWithDebInfo`, or `MinSizeRel`.  
     To disable building the tests, append ` -DBUILD_TESTING=OFF` to the `cmake -S . -B build` command.

4. ### Build the main executable/library:
```
cmake --build build
```  
   - For multi-configuration generators(**only** Xcode and Visual Studio), the build type can be selected by appending the following to the `cmake --build build` command:
```--config BUILD_TYPE```  
Where `BUILD_TYPE` is `Debug`, `Release`, `RelWithDebInfo`, or `MinSizeRel`.

5. ### Running the tests:  
For single-configuration generators(everything **but** Xcode and Visual Studio):
```
cmake --build build -t test
```  
For multi-configuration generators(**only** Xcode and Visual Studio):
```
cmake --build build -t RUN_TESTS
```  
You may need to select the build type(for multi-configuration generators only). Append `--config BUILD_TYPE`, where `BUILD_TYPE` is `Debug`, `Release`, `RelWithDebInfo`, or `MinSizeRel`. `BUILD_TYPE` should be the same as used in step #4.  
Note that the test target does not rebuild anything. As a result, you may want to run `cmake --build build` before running the tests after making changes.

<a name="running"></a>
# Running
After completing the [Building & Testing](#building_testing) steps, the binaries are located in `build/bin/`, and the library and archive files in `build/lib/`. Examples and documentation are provided below.  

TODO: Add some examples of running the program!


<a name="libraries_used"></a>
# Libraries Used
* [{fmt}](https://github.com/fmtlib/fmt)
* [doctest](https://github.com/onqtam/doctest/)

<a name="contributors"></a>
# Contributors
* Add your name here!
* CMake Base Project: Jared White @@TODO
