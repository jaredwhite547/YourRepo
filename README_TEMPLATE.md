<p align="center"><img width="45%" src="adapt-logo.png"></p>
  
# YourProject
A tldr of your project. Something like:  
### [YourProject] is a cross platform [MIT/GPL/whatever]-Licensed C++14 [application/library/thing] for [doing something awesome].

# Table of Contents
1. [Introduction](#introduction)
2. [Dependencies](#dependencies)
3. [Building, Testing, & Installation](#building_testing_installing)
    1. [On Boise State's R2](#building_testing_installing_on_r2)
    2. [On a normal machine](#building_testing_installing_on_a_normal_machine)
4. [Running](#running)
5. [Libraries Used](#libraries_used)

<a name="introduction"></a>
# Introduction
A longer description of your awesome project!

<a name="dependencies"></a>
# Dependencies
* CMake 3.14 or newer
* A C++14 capable compiler
* (Optional) Doxygen, for building documentation.

<a name="building_testing_installing"></a>
# Building, Testing, & Installing
<a name="building_testing_installing_on_r2"></a>
## On Boise State's R2
Load the the required modules:  
```module load cmake gcc```  
Follow the steps for [on a normal machine](#building_tesitng_installing_on_a_normal_machine)

<a name="building_testing_installing_on_a_normal_machine"></a>
## On a normal machine
1. Clone the repository:   
```
git clone git@github.com:BoiseState-AdaptLab/YourProject.git
```

2. `cd` into the directory:  
```
cd YourProject
```

3. Generate the build files:  
```
cmake -S . -B build
```

   - The default build type is Debug. To change it for single-configuration generators (everything but Xcode and Visual Studio), append the following to the `cmake -S . -B build` command:  
``` -DCMAKE_BUILD_TYPE=BUILD_TYPE```  
Where `BUILD_TYPE` is `Debug`, `Release`, `RelWithDebInfo`, or `MinSizeRel`.  
     To disable building the tests, append ` -DBUILD_TESTING=OFF` to the `cmake -S . -B build` command.

4. Build the main executable/library:
```
cmake --build build
```  
   - For multi-configuration generators(only Xcode and Visual Studio), the build type can be selected by appending the following to the `cmake --build build` command:
```--config BUILD_TYPE```  
Where `BUILD_TYPE` is `Debug`, `Release`, `RelWithDebInfo`, or `MinSizeRel`.

5. Running the tests:  
```
cmake --build build -t test
```  


6. (Optional) Building the docs (requires Doxygen):  
```
cmake --build build -t docs
```  
The html files can be found in `build/html`. Open the `build/html/index.html` file with your preferred browser to view them.

7. (Optional) Installation
Note: This step is not required. It is for those who would like to install YourProject system-wide. The install location defaults to `/usr/local` or `c:/Program Files/YourProject`, and can be overridden by setting `CMAKE_INSTALL_PREFIX` to something else.
```
cmake --build build -t install
```

<a name="running"></a>
# Running
After completing the [Building, Testing, & Installing](#building_testing_installing) steps, the binaries are located in `build/bin/`, and the library and archive files in `build/lib/`. Examples and documentation are provided below.  
TODO: Add some examples of running the program!


<a name="libraries_used"></a>
# Libraries Used
* [{fmt}](https://github.com/fmtlib/fmt)
* [doctest](https://github.com/onqtam/doctest/)
