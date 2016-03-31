cmake_minimum_required(VERSION 3.4)
project(Test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c main.h utils.c utils.h
        sample_code/multiway_main.c sample_code/multiway_main.h sample_code/multiwayMergesort.c sample_code/multiwayMergesort.h sample_code/multiway_main.h sample_code/make_rand_file.c sample_code/make_rand_file.h)
add_executable(Test ${SOURCE_FILES})