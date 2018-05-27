message(STATUS "Gathering project files")
file(GLOB_RECURSE INCS "src/*.h")
file(GLOB_RECURSE SRCS "src/*.cpp")
add_executable(tic-tac-toe ${SRCS} ${INCS})