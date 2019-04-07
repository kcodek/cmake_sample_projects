## 1. Project_01 

* A simple "Hello World" with a  single cpp file       
    $ tree -L 2 

        ├── CMakeLists.txt
        ├── build
        │   ├── CMakeCache.txt
        │   ├── CMakeFiles
        │   ├── Makefile
        │   ├── cmake_install.cmake
        │   └── exe01
        └── main_01.cpp

## 2. Project_02
* A complicated "Hello World" with a single cpp file. However this file uses c++14 features.        
    $ tree -L 2 

        ├── CMakeLists.txt
        ├── build
        │   ├── CMakeCache.txt
        │   ├── CMakeFiles
        │   ├── Makefile
        │   ├── cmake_install.cmake
        │   └── exe01
        └── main_01.cpp
* This is based on Jason Turner's CMake tutorial:  https://youtu.be/HPMvU64RUTY         

## 3. Project_03
* An executable that uses a with shared library     
    $ tree -L 3      

        .
        ├── CMakeLists.txt
        ├── app
        │   ├── CMakeLists.txt
        │   └── main_03.cpp
        ├── build
        │   ├── CMakeCache.txt
        │   ├── CMakeFiles
        │   │   ├── 3.14.1
        │   │   ├── CMakeDirectoryInformation.cmake
        │   │   ├── CMakeOutput.log
        │   │   ├── CMakeTmp
        │   │   ├── Makefile.cmake
        │   │   ├── Makefile2
        │   │   ├── TargetDirectories.txt
        │   │   ├── cmake.check_cache
        │   │   ├── exe03.dir
        │   │   ├── feature_tests.bin
        │   │   ├── feature_tests.c
        │   │   ├── feature_tests.cxx
        │   │   └── progress.marks
        │   ├── Makefile
        │   ├── app
        │   │   ├── CMakeFiles
        │   │   ├── Makefile
        │   │   ├── cmake_install.cmake
        │   │   └── exe03
        │   ├── cmake_install.cmake
        │   └── library
        │       ├── CMakeFiles
        │       ├── Makefile
        │       ├── cmake_install.cmake
        │       └── libcustomer.dylib
        └── library
            ├── CMakeLists.txt
            ├── include
            │   └── customer.h
            └── src
                └── customer.cpp

* This is based on Deniz Bahadir's MoreModernCMake - https://youtu.be/y7ndUhdQuU8           

## 4. Project depending on a external git repo 
* $ tree -L 2                                                                                                                                   
        
        ├── CMakeLists.txt
        ├── app
        │   ├── CMakeLists.txt
        │   └── main_04.cpp
        ├── build
        │   ├── CMakeCache.txt
        │   ├── CMakeFiles
        │   ├── Makefile
        │   ├── app
        │   ├── cmake_install.cmake
        │   └── external
        └── external
            ├── CMakeLists.txt
            └── nlohmann_json

* To allow the project to support either an externally supplied or an embedded JSON library 
    - Embedded
        - To embed the library directly into an existing CMake project, place the entire source tree in a subdirectory and call add_subdirectory() in your CMakeLists.txt file
    - External
        - To use this library from a CMake project, you can locate it directly with find_package() and use the namespaced imported target from the generated package configuration  
            > CMakeLists.txt
                find_package(nlohmann_json 3.2.0 REQUIRED)
                ...
                add_library(foo ...)
                ...
                target_link_libraries(foo PRIVATE nlohmann_json::nlohmann_json)  
* CMake
    - You can also use the nlohmann_json::nlohmann_json interface target in CMake. 
    - This target populates the appropriate usage requirements for INTERFACE_INCLUDE_DIRECTORIES to point to the appropriate include directories and INTERFACE_COMPILE_FEATURES for the necessary C++11 flags.                

## 5. Executable, Library (shared, static)
## 6. Project using the lib files
## 7. Project with mulitple directories



### useful cmake commands
> pwd: Project_01/
- `$ cmake -S . -B build`
- `$ cmake --build build`   


### More modern cmake
* CMake is a build-system generator. It generates input files for build-generators.
    Supports: Make, Ninja, Visual Studio, XCode, ...

* Modern CMAKE - "everything is a (self-contained) target"
* Build Requirements of a Target :  "Everything that is needed to (successfully) build that target."
    - source-files
    - include search-paths 
    - pre-processor 
    - macros 
    - link-dependencies 
    - compiler/linker-options 
    - compiler/linker-features (e.g. support for a C++-standard)

    _Adding build-requirements_ 

        target_include_directories(<target> PRIVATE <include-search-dir>... ) 
        target_compile_definitions(<target> PRIVATE <macro-definitions>... )   
        target_compile_options(<target> PRIVATE <compiler-option>... )        
        target_compile_features(<target> PRIVATE <feature>... )           
        target_sources(<target> PRIVATE <source-file>... )        
        target_link_libraries(<target> PRIVATE <dependency>... )      
        target_link_options(<target> PRIVATE <linker-option>... )     
        target_link_directories(<target> PRIVATE <linker-search-dir>... )     



* Usage Requirements of a Target : "Everything that is needed to (successfully) use that target." "As a dependency of another target."
    - source-files (but normally not)
    - include search-paths 
    - pre-processor
    - macros 
    - link-dependencies 
    - compiler/linker-options 
    - compiler/linker-features (e.g. support for a C++-standard)

    _Adding usage-requirements_

        target_include_directories(<target> INTERFACE <include-search-dir>... )
        target_compile_definitions(<target> INTERFACE <macro-definitions>... )
        target_compile_options(<target> INTERFACE <compiler-option>... )
        target_compile_features(<target> INTERFACE <feature>... )
        target_sources(<target> INTERFACE <source-file>... )
        target_link_libraries(<target> INTERFACE <dependency>... )
        target_link_options(<target> INTERFACE <linker-option>... )
        target_link_directories(<target> INTERFACE <linker-search-dir>... )

* use 'PUBLIC' when the requirement is both build and usage
* In CMake, `target_link_libraries` is used to model dependencies between targets. 
    Warning: Although `target_link_libraries` can be used without these keywords, you should never forget to use these keywords in Modern CMake!

* Finding External Dependency - BOOST
* Using `find_package` to locate Boost. If found, sets variables:
    `Boost_INCLUDE_DIRS`, containing include-path
    `Boost_LIBRARIES`, containing file-paths to shared libraries

    > find_package( Boost ${BOOST_VERSION} EXACT REQUIRED 
        COMPONENTS program_options graph )
* Modern CMake additionally creates IMPORTED targets:
  `Boost::boost`
  `Boost::program_options`
  `Boost::graph`
    - IMPORTED targets carry and can propagate their usage-requirements.
    - Variables and IMPORTED targets created by find_package have non-global scope
    - Since CMake 3.11 IMPORTED targets can be promoted to global scope by setting the IMPORTED_GLOBAL property to TRUE.
    - Promoted/Global IMPORTED targets cannot be demoted!

* Creating IMPORTED target for external dependenct -  BOOST.OUTCOME    
    - For usage-requirements the INTERFACE_... properties need to be set. 
    - using `target_...` commands does not work with IMPORTED libraries till 3.11
    - Even ALIASing IMPORTED targets is now possible.

* include_directories adds include-search-paths on directory-scope applies to all targets from that CMakeLists.txt
    - Not transitive, only sets build-requirements!, Compile-features have to be set by hand.
    - set in CMAKE_CXX_FLAGS cache-variable .. Not transitive, instead a global build-requirement!
    - Modern CMake is more flexible (and explicit) by using `target_include_directories` and `target_compile_features` commands

* Usage-requirements of dependencies need to become build-requirements of dependent targets using the same commands.
    till 3.11, even with Modern CMake, OBJECT targets cannot declare dependency on other targets, and therefore need to add usage-requirements of dependencies by hand.
    - Since CMake 3.12 the target_link_libraries command can be used with OBJECT targets.


### Modern CMake
-----
* Declare your module with ADD_LIBRARY or ADD_EXECUTABLE
* Declare your build flags with TARGET_xxx()
* Declare your dependencies with TARGET_LINK_LIBRARIES
* Specify what is PUBLIC and What is PRIVATE
* Link against targets to get their build flags

* Each module has a set of private flags - required to build its implementation
* Each module has a set of public flags - required to build against its interface
* Build interfaces are transitive

* Dependencies are public or private:
    - Public dependencies are transitive & will be passed down to clients
    - Private dependencies are not

* Anti-patterns
    - Don't use macros that affect all targets
        - INCLUDE_DIRECTORIES()
        - ADD_DEFINITIONS()
        - LINK_LIBRARIES
    - Don't use TARGET_INCLUDE_DIRECTORIES() with a path outside your module
    - Don't use TARGET_INCLUDE_DIRECTORIES() without specifying PUBLIC, PRIVATE or INTERFACE
    - Don't use TARGET_COMPILE_OPTIONS() to set flags that affect the ABI 


* External Projects
    - External projects should be targets too
    - CMake built-in finders have undergone an effort in that case
        > find_package(GTest)   
            add_executable(foo ...)     
            target_link_libraries(foo GTest::GTest GTest::Main) 

    - Modern finders provide targets instead of flags
        - 3.4: OpenSSL
        - 3.5: Boost, GTest, GTK, PNG, TIFF
        - 3.6: PkgConfig
        - 3.7: Bzip2, OpenCL
        - 3.8: OpenGL  

    - User modern finders that declare targets 
    - Generate them with CMake from your actual project definition
    - Use a package manager
    > find_library(BAR_LIB bar HINTS ${BAR_DIR}/lib)
        add_library(bar SHARED IMPORTED
                        LOCATION ${BAR_LIB})
        target_include_directories(bar INTERFACE ${BAR_DIR}/include)
        target_link_libraries(bar INTERFACE Boost::boost)

    >find_library(BAR_LIB bar HINTS ${BAR_DIR}/lib)
        add_library(bar SHARED IMPORTED)
        set_target_properties(bar PROPERTIES
                     LOCATION ${BAR_LIB})
        set_target_properties(bar PROPERTIES 
            INTERFACE_INCLUDE_DIRECTORIES $ {BAR_DIR}/include)
            INTERFACE_LINK_LIBRARIES Boost::boost) 

-----

`project()`
Sets the name of the project, and stores it in the variable `PROJECT_NAME`. When called from the top-level CMakeLists.txt also stores the project name in the variable `CMAKE_PROJECT_NAME`. Also sets the variables `PROJECT_SOURCE_DIR, <PROJECT-NAME>_SOURCE_DIR & PROJECT_BINARY_DIR, <PROJECT-NAME>_BINARY_DIR`

Contents of `INTERFACE_INCLUDE_DIRECTORIES` may use “generator expressions” with the syntax `$<...>`.

----

`target_compile_features`(<target> <PRIVATE|PUBLIC|INTERFACE> <feature> [...])
    Add expected compiler features to a target.

Specifies compiler features required when compiling a given target.  If the feature is not listed in the ``CMAKE_C_COMPILE_FEATURES`` variable
or ``CMAKE_CXX_COMPILE_FEATURES`` variable, then an error will be reported by CMake.  If the use of the feature requires
an additional compiler flag, such as ``-std=gnu++11``, the flag will be added automatically.

The ``INTERFACE``, ``PUBLIC`` and ``PRIVATE`` keywords are required to specify the scope of the features.  
- ``PRIVATE`` and ``PUBLIC`` items will populate the ``COMPILE_FEATURES`` property of ``<target>``.
- ``PUBLIC`` and ``INTERFACE`` items will populate the ``INTERFACE_COMPILE_FEATURES`` property of ``<target>``.

(:ref:`IMPORTED targets <Imported Targets>` only support ``INTERFACE`` items.) 
Repeated calls for the same ``<target>`` append items.

The named ``<target>`` must have been created by a command such as ``add_executable()`` or ``add_library()`` and must not be an :ref:`ALIAS target <Alias Targets>`.

* Note that there is no reason to manually append -std=c++11 to CMAKE_CXX_FLAGS, let CMake do that for you! 
    Stay away from variable land, model your requirements via properties.

----
