cmake_minimum_required(VERSION 3.12)

project(ComplicatedHelloWorld)

add_executable(exe02)

target_sources(exe02 PRIVATE main_02.cpp)

target_compile_features(exe02 PRIVATE cxx_lambda_init_captures) # without this feature => error: expected expression