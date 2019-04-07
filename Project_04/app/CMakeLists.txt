cmake_minimum_required( VERSION 3.12)

project( ExternalDependency 
            VERSION 1.0.0   
            DESCRIPTION "An app that uses a src from an external project")

add_executable(exe04)            

target_sources(exe04 PRIVATE main_04.cpp)

target_compile_features(exe04 PRIVATE cxx_std_14)

# Note that the namespaced target will always be available regardless of the
# import method
target_link_libraries(exe04 PRIVATE nlohmann_json::nlohmann_json)

