cmake_minimum_required(VERSION 3.12)

project( Application
            VERSION 1.0
            DESCRIPTION " An app that uses a SHARED library " )



add_executable(exe03)
target_sources(exe03 PRIVATE main_03.cpp)
target_link_libraries(exe03 PRIVATE customer) # uses shared lib # libcustomer.dylib
target_compile_features(exe03 PRIVATE cxx_std_14)

add_executable(exe03_static)
target_sources(exe03_static PRIVATE main_03.cpp)
target_link_libraries(exe03_static PRIVATE customer_static) # uses static lib  # libcustomer_static.a
target_compile_features(exe03_static PRIVATE cxx_std_14)