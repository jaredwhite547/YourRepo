
There are three use cases: @@TODO

#Adding External Library
If the library uses CMake, and uses it properly, you can use FetchContent, as shown in this example with the fmt and @@TODO catch2 library. If the library doesn't support CMake, the easiest way is to use or write a find module.

#Recommended Libraries
If your app has, or will have a CLI interface that isn't dead simple, you probably want a command line option parsing library. @@TODO

The included formatting/IO library, {fmt}, is very good. The majority of is being standardized with later C++ versions, so it is hard to go wrong here.

#Testing frameworks
* This project uses doctest.@@TODO It is almost identical to catch2, but the compile and linking times are much much faster. Both are good choices

