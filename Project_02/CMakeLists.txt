cmake_minimum_required(VERSION 3.12)

project( SingleFile2
            VERSION 1.0
            DESCRIPTION " A complicated hello world executable" )

add_executable(exe02)

target_sources(exe02 PRIVATE main_02.cpp)

target_compile_features(exe02 PRIVATE cxx_std_14)

# target_compile_features(exe02 PRIVATE cxx_lambda_init_captures) # without this feature => error: expected expression