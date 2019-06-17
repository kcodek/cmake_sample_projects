## cpp-cmake-test

*cmake_minimum_required(VERSION  version  FATAL_ERROR)*
This command specifies the minimum version of CMake that can be used with  `CMakeLists.txt`  file. The first argument must be  `VERSION`  verbatim. The next is the minimum version of CMake that can be used. The last is optional, but should be included, it must be  `FATAL_ERROR`  verbatim. It is recommended that this command be used in all top level  `CMakeLists.txt`. If you aren’t sure what version to set use the version of CMake you have installed.

*project(name)*
The  `project`  command names your project. Optionally you can specify what language the project supports, any of  `CXX`,  `C`,  `JAVA`, or  `FORTRAN`. CMake defaults to  `C`  and  `CXX`  so if you do not have compilers for C++ installed you may need to specify the language supported so that CMake doesn’t search for it.

*add_executable(target  sources…)*
This command tells CMake you want to make an executable and adds it as a target. The first argument is the name of the executable and the rest are the source files. You may notice that header files aren’t listed. CMake handles dependencies automatically so headers don’t need to be listed.

*cmake -G "Unix Makefiles" ..*
Use CMake to setup a build using Unix Makefiles.
*-G  \<generator name\>*
This allows us to tell CMake what kind of project file it should generate. In this example I wanted to use a Makefile. Which generators are available depends on your platform, use  cmake --help  to list them. 
*\<path to source\>*
The path to the source code. When doing out-of-source builds as is recommended the source code could be anywhere relative to the build directory. This path should be to the directory containing your top level  `CMakeLists.txt`. In this example the source is in the parent directory so the path is ‘`..`‘.


*make VERBOSE=1*
Run  `make`  to build our target executable. Since we chose “Unix Makefiles” as our generator CMake created a Makefile for us.

Makefile created by CMake is quite fancy and has nice color output. This Makefile suppresses the standard output. While this provides a neater and cleaner experience it can make debugging more difficult as you can’t check the flags passed to the compiler, etc. Before you start worrying you can get all of that output by running make VERBOSE=1. 

*CMAKE_CURRENT_SOURCE_DIR* - The full path to the source directory that C Make is currently processing.

*enable_testing()*
Enables testing for this CMake project. This should only be used in top level  `CMakeLists.txt`. The main thing this does is enable the  `add_test()`  command.
 
 *add_test(testname  executable  arg1 …)*
This command only does something if the  `enable_testing()`  has already been run, otherwise it does nothing. This adds a test to the current directory that will be run by CTest. The executable can be anything, so it could be a test program, e.g. a unit test created with something like Google Test, a script, or any other test imaginable.  
_Note:_  Tests are not run automatically and if your test program is built as part of your project the test target will not ensure it is up to date. It is best to build all other targets before running the test target.

*make test*
The  `enable_testing()`  function we added to our  `CMakeLists.txt`  adds the “test” target to our Makefile. Making the “test” target will run CTest which will, in turn, run all of our tests. 
When CTest runs our tests it prints an abbreviated output that just provides the status of each of our tests. It then finishes up with a summary of all tests.

*Testing/Temporary/LastTest.log*
This file is created by CTest whenever it is run. It contains much more detail than the terminal output of CTest shows. Most importantly it contains the output of the tests. This is where you will want to look whenever a test fails.

*Testing/Temporary/CTestCostData.txt*
This file contains the time, in seconds, taken to run each test.
CMake along with CTest makes it easy to run our tests. CTest has many other features which will be presented later in this tutorial. There are, however, a few drawbacks to running our tests this way but we will leave those for later, too.



*include_directories(directories)* -
Add 'directories' to the end of this directory’s include paths.
*include_directories(AFTER|BEFORE SYSTEM directory…)*
*AFTER|BEFORE* - Specify whether or not these include directories should be appended or prepended to the list of include directories. If omitted then the default behavior is used.
By default directories are appended to the list. This behavior can be changed by setting CMAKE_INCLUDE_DIRECTORIES_BEFORE to TRUE.
*SYSTEM* - Specify that these directories are system include directories.
This only has an affect on compilers that support the distinction. This can change the order in which the compiler searches include directories or the handling of warnings from headers found in these directories.

*directory*… The directories to be added to the list of include directories.

  
  
  

 *add_subdirectory(source_dir)*
 Include the directory source_dir in your project. This directory must contain a CMakeLists.txt file.

When adding a directory that is a subdirectory of the current directory CMake will automatically determine what the binary output directory should be,making the second argument optional.  However if you add a directory that isn’t a subdirectory you need to specify the binary output directory.

  
  

 *target_link_libraries(target library…)* 
Specify that target needs to be linked against one or more libraries. If a library name matches another target dependencies are setup automatically so that the libraries will be built first and target will be updated whenever any of the libraries are.

If the target is an executable then it will be linked against the listed libraries.

If the target is a library then its dependency on these libraries will be recorded. Then when something else links against target it will also link against target‘s dependencies. This makes it much easier to handle a library’s dependencies since you only have to define them once when you define library itself.

  

*add_library(target STATIC | SHARED | MODULE sources…)*
This command creates a new library target built from sources. As you may have noticed this command is very similar to add_executable.

With *STATIC, SHARED, and MODULE* you can specify what kind of library to build.

*STATIC* libraries are archives of object files that are linked directly into other targets.
*SHARED* libraries are linked dynamically and loaded at runtime.
*MODULE* libraries are plug-ins that aren’t linked against but can be loaded dynamically at runtime.

If the library type is not specified it will be either STATIC or SHARED.
The default type is controlled by the BUILD_SHARED_LIBS variable. By default static libraries are created.


*CMAKE_BINARY_DIR* - This variable holds the path to the top level binary output directory, i.e. the directory in which you ran the cmake command or the path you chose for “Where to build the binaries” in the GUI.

*option(name  docstring  initialValue)*
Provide a boolean option to the user. This will be displayed in the GUI as a checkbox. Once created the value of the option can be accessed as the variable  `name`. The  `docstring`  will be displayed in the GUI to tell the user what this option does. If no initial value is provided it defaults to OFF.

While this boolean option is stored in the cache and accessible as a variable you cannot override the  `initialValue`  by setting a variable of the same name beforehand, not even by passing a  -D  command line option to CMake. Which is why we have to define the option ourselves before Google Test does.


*add_definitions(flags…)*
Add preprocessor definitions to the compiler command line for targets in the current directory and those below it. While this command is intended for adding definitions you still need to precede them with  `-D`.

Because this command modifies the  `COMPILE_DEFINITIONS`  directory property it affects  _all_  targets in the directory, even those that were defined  **before**  this command was used. If this is not the desired effect then modifying the  `COMPILE_DEFINITIONS`  property of particular targets or source files will work better. (Properties are introduced below.)


##### cpp-cmake-test is based on:
 - https://www.johnlamp.net/cmake-tutorial-1-getting-started.html