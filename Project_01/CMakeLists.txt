cmake_minimum_required(VERSION 3.12)

project( SingleFile
            VERSION 1.0
            DESCRIPTION " A simple hello world executable" )

# todo: C+14 hello world            

add_executable( exe01 )
target_sources(exe01 PRIVATE main_01.cpp)

