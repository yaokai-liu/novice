cmake_minimum_required(VERSION 3.22)
project(novice CXX ASM)

set(CMAKE_C_COMPILER "/usr/bin/${TARGET}-linux-gnu-gcc-11")
set(CMAKE_CXX_COMPILER "/usr/bin/${TARGET}-linux-gnu-g++-11")
set(CMAKE_ASM_COMPILER "/usr/bin/${TARGET}-linux-gnu-as")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output")

include_directories(include)

aux_source_directory(csrc C_SRC)
add_library(csrc STATIC ${C_SRC})

if (${TARGET} STREQUAL "x86_64")
    set(ASM_FLAGS "-march=generic64")
    set(CXX_FLAGS "-march=x86-64")
elseif (${TARGET} STREQUAL "aarch64")
    set(ASM_FLAGS "-march=armv8-a" "-mlittle-endian" "-mabi=lp64")
    set(CXX_FLAGS "-march=armv8-a" "-mlittle-endian" "-mabi=lp64")
elseif (${TARGET} STREQUAL "riscv64")
    set(ASM_FLAGS "-march=rv64imd" "-mabi=lp64d")
    set(CXX_FLAGS "-march=rv64imd" "-mabi=lp64d")
endif ()

aux_source_directory(tests TEST)
add_executable(test-${TARGET} ${TEST})
target_link_libraries(test-${TARGET} PRIVATE ${TARGET} csrc gtest)
target_compile_options(test-${TARGET} PRIVATE ${CXX_FLAGS})

file(GLOB ARCH ${TARGET}/*.s)
add_library(${TARGET} STATIC ${ARCH})
target_compile_options(${TARGET} PRIVATE ${ASM_FLAGS})
