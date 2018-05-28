
# List options
option(ENVIROMENT_DEV "Module will check for extended errors. This is NOT recommended in production enviroment")

# Enable options

if(ENVIROMENT_DEV)
    message(STATUS "Building for development enviroment, extended checks enable.")
    message(STATUS "To build for production use 'cmake -DENVIROMENT_DEF=FALSE .")
    add_definitions(-DEXTENDED_CHECKS)
else(ENVIROMENT_DEV)
    message(STATUS "Building for production enviroment, no extended checks included")
    message(STATUS "To build for development use 'cmake -DENVIROMENT_DEF=TRUE .")
endif(ENVIROMENT_DEV)
