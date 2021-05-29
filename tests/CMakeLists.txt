include(FetchContent)

#Fetch the testing framework from github
message(STATUS "Fetching content: doctest")
FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/onqtam/doctest.git
    GIT_TAG 2.4.6
)

FetchContent_MakeAvailable(doctest)
message(STATUS "doctest successfully fetched.")

#Add our two test directories
add_subdirectory(MathUtils)
add_subdirectory(MathUtils-bin)


#This is a bit of magic taken from https://stackoverflow.com/a/63732435
#By default, the test target in cmake does not actually build anything, which is dumb. This magic fixes that. You don't need to understand it, just know it lets you run `cmake --build build -t test` and it will (re)build anything out of date.
file(WRITE "${CMAKE_BINARY_DIR}/CTestCustom.cmake"
    "set(CTEST_CUSTOM_PRE_TEST ${CMAKE_MAKE_PROGRAM})\n"
)
