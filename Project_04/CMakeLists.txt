cmake_minimum_required(VERSION 3.12)

Project( ThirdParty
            VERSION 1.0.0
            DESCRIPTION "A project that supports either an externally supplied or an embedded JSON library" )            


set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(THIRDPARTY_USE_EXTERNAL_JSON "Use an external JSON library" OFF)


add_subdirectory(app)

add_subdirectory(external)

