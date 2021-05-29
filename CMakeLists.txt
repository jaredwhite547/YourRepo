#=====Basic Setup=====
#Specify minimum CMake version
cmake_minimum_required(VERSION 3.14)

#Create a new project
project(MathUtils VERSION 1.0.0 
    #@@TODO replace below with your description
    DESCRIPTION "MathUtils project"
    LANGUAGES CXX
)


#=====Declare Targets=====
#Create the main library
add_library(MathUtils)

#Create the main executable
add_executable(MathUtils-bin)
#Change the executable output name (by default it would be MathUtils-bin)
set_target_properties(MathUtils-bin PROPERTIES OUTPUT_NAME MathUtils)


#=====Declare Dependencies=====
#Make MathUtils-bin (our driver) depend on our library (MathUtils)
target_link_libraries(MathUtils-bin PRIVATE MathUtils)

#Set the include directory for this library. PUBLIC means this directory is propagated to any targets that link to it.
target_include_directories(MathUtils PUBLIC include)


#Fetch the fmt library
include(FetchContent)
message(STATUS "Fetching content: fmt")
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 7.1.3
)
FetchContent_MakeAvailable(fmt)
message(STATUS "fmt successfully fetched.")

#Make it a dependency of the executable (the MathUtils-bin target, not MathUtils)
target_link_libraries(MathUtils-bin PRIVATE fmt)


#=====Tweak build settings=====
#Set standard to C++14, require it, and turn off extensions (more portable code). Also make the directory structure more traditional (lib stuff in lib, execs in bin)
set_target_properties(MathUtils PROPERTIES 
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

set_target_properties(MathUtils-bin PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

#If this project is being directly built (NOT as a dependency of another project)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    #Set the default build type to Debug
    #The `NOT CMAKE_CONFIGURATION_TYPES` makes the if statement only apply to single config generators (basically NOT visual studio and NOT xcode)
    if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
        message(STATUS "No build type set, defaulting to Debug")
        set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the build type." FORCE)
        #Set valid options
        set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
            "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
    endif()

    #If testing wasn't explictly set, enable building it.
    if(NOT BUILD_TESTING)
        message(STATUS "Enabling testing")
        set(BUILD_TESTING ON)
    endif()

    #Enable a bunch of warnings
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU") #Clang or GCC/G++
        set(compiler_warnings
            "-Wall;-Wextra;-Wshadow;-Wnon-virtual-dtor;-pedantic;-Wcast-align;-Wunused;-Woverloaded-virtual;-Wpedantic;-Wconversion")
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC") #Microsoft Visual Studio
        set(compiler_warnings "/permissive;/W4")
    endif()

    target_compile_options(MathUtils PRIVATE ${compiler_warnings})
    target_compile_options(MathUtils-bin PRIVATE ${compiler_warnings})
endif()

#Add source directory
add_subdirectory(src)

#If this project is being built, and the tests are requested:
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    #Enable testing
    include(CTest)
    add_subdirectory(tests)
endif()
