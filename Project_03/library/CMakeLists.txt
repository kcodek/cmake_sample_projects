cmake_minimum_required(VERSION 3.12)

project(Customer
        VERSION 1.0.0
        DESCRIPTION "A Customer class library")

add_library(customer_objLib OBJECT) # building object library to avoid the duplicated compilation of the object files

target_sources(customer_objLib
        PRIVATE "src/customer.cpp"
        PRIVATE  "${CMAKE_CURRENT_SOURCE_DIR}/include/customer.h")

# Required include search-paths 
target_include_directories(customer_objLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")        
target_compile_features(customer_objLib PRIVATE cxx_std_14)

# A shared library for basic-math functionality.
add_library( customer SHARED )
target_link_libraries( customer PUBLIC customer_objLib )

# A static library for basic-math functionality.
add_library( customer_static STATIC )
target_link_libraries( customer_static PUBLIC customer_objLib )
