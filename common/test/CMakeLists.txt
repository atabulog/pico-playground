# Generated Cmake Pico project file
cmake_minimum_required(VERSION 3.13)

project(pico-sandbox-tests C CXX ASM)

#use C11 and C++17
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#use standard gcc compilers
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_ASM_COMPILER /usr/bin/gcc)
#set variables for later usage
set(COMMON_SRC_DIR "${COMMON_SRC_DIR}/src")

# =============================================================================
# establish tests for library
if ( NOT DEFINED ENABLE_TESTS )
    set(ENABLE_TESTS TRUE)
endif(NOT DEFINED ENABLE_TESTS)
option(ENABLE_COVERAGE "Enable code coverage reporting" OFF)

if (ENABLE_TESTS)
    # Create tests for common-lib
    message(STATUS "Building common-lib tests")
    INCLUDE(CTest)
    enable_testing()
    # enable google test framework
    set(GTEST_LIBRARY "/usr/lib/libgtest.a")
    set(GTEST_MAIN_LIBRARY "/usr/lib/libgtest_main.a")
    set(GTEST_INCLUDE_DIR "/usr/include")
    find_package(GTest REQUIRED)
    if(NOT ${GTEST_FOUND})
        message(FATAL_ERROR "GTest not found")
    endif()
    # enable multi-threading for tests
    find_package(Threads REQUIRED)
    if(NOT ${THREADS_FOUND})
        message(FATAL_ERROR "Threads not found" )
    endif()

    # create test lib bundle
    set(TEST_LIBS
        GTest::GTest
        GTest::Main
        GTest::gmock
        Threads::Threads
    )

    # add test subdirectories
    #add_subdirectory(data)
    add_subdirectory(memory_map)
    #add_subdirectory(utils)
endif(ENABLE_TESTS)




