#Create a new target executable called MathUtils_test
add_executable(MathUtils_test MathUtils.test.cpp)

#Make it's binaries appear in the build/bin folder, for ease of use.
set_target_properties(MathUtils_test PROPERTIES 
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

#Add one test file per source/header file below:
target_sources(MathUtils_test PRIVATE
    DotProduct.test.cpp
)

#Link it to the testing framework and main program library.
target_link_libraries(MathUtils_test doctest::doctest MathUtils)

#Register it wth CMake. If the target and the executable have the same name (which will be true unless it has been explicitly renamed, as we did with MathUtils-bin), COMMAND can just be the name of the target, as shown here.
add_test(NAME MathUtils_test COMMAND MathUtils_test)
