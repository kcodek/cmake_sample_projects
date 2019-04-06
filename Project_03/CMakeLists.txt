cmake_minimum_required(VERSION 3.12)


project( MultiFile
            VERSION 1.0
            DESCRIPTION " A executable that uses a shared library " )


# Always use '-fPIC'/'-fPIE' option.
set( CMAKE_POSITION_INDEPENDENT_CODE ON )            

# Create targets for building the (local) libraries.
add_subdirectory( library )


# Create the targets for the entire example-app.
add_subdirectory( app )
