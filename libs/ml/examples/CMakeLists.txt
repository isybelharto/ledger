################################################################################
# F E T C H   M L   E X A M P L E S
################################################################################
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(fetch-ml)

# CMake configuration
include(${FETCH_ROOT_CMAKE_DIR}/BuildTools.cmake)

# Compiler Configuration
setup_compiler()

setup_library_examples(fetch-ml)

if (FETCH_ENABLE_EXAMPLES)


endif(FETCH_ENABLE_EXAMPLES)
