cmake_minimum_required(VERSION 3.17)
project(kkk C ASM)

set(CMAKE_C_STANDARD 99)

aux_source_directory(src VM_SRCS)

SET(VM_BIN src/main.c ${VM_SRCS} src/darwin_callNative.S)

add_executable(java ${VM_BIN})

target_link_libraries(java pthread m z dl)