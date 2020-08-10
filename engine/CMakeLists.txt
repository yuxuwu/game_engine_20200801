project(engine)



##########################################
## Build external libraries
##########################################
add_subdirectory(external-libs/googletest)



##########################################
## Build engine lib
##########################################
#add_library(engine engine.cpp)



##########################################
## Build tests
##########################################
enable_testing()
add_executable(runUnitTests test.cpp)
target_link_libraries(runUnitTests gtest gmock gmock_main)
add_test(runUnitTests runUnitTests)