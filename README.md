# CMake Example
This is a small project intended to serve as an example


# How to use this example for your own project.
The project is currently set up to be used as a library and an application
1. Clone and rename this repo to your project name.
2. Push it to a new repo, ideally with the same name as your project.
3. 


There are a few bits of functionality missing from this project. This was done to keep the size of this example relatively small. The missing functionality is:
1. 

@@TODO try these instructions and test them

You may consider enabling -Werror for the CI.

# How to use this example for a project with no driver/application (library only)
1. Follow the previous instructions
2. Delete/comment everything that references MathUtils-bin. 

#Things to replace:
YourProject with your project name
MathLib with your project name

There are three use cases: @@TODO

#Adding External Library
If the library uses CMake, and uses it properly, you can use FetchContent, as shown in this example with the fmt and @@TODO catch2 library. If the library doesn't support CMake, the easiest way is to use or write a find module.

# Things this example does not do
* Allow for the project to be used as a dependency(i.e. dedicated library project). About half the work is done, the other half was omitted to keep the size small.
* Allow for proper system-wide installation using CMake. As with the previous point, this was omitted to keep the project short.
* Build Doxygen documentation
* Build hosted documentation

# Resources used
@@TODO


# CMake_Example
This project is a small example project showing how to 


# Libraries Used
* [doctest](https://github.com/onqtam/doctest/) is the testing library used here. It is similar to `catch2`, but compiles much faster.
* [{fmt}](https://github.com/fmtlib/fmt)


# License
The **code** for this repository and `CoolLogo.png` is CC0/public domain(The libraries used are only fetched during build times. This means the binaries are (probably, I'm not a lawyer) not CC0. Since this is an example project, and no binaries are being distributed, it doesn't matter. CC0/public domain means this code this completely free, you can do anything you want with it. If you would like this code released under a different license (like BSD0 for example), please open an issue.
