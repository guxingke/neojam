cmake_minimum_required(VERSION 3.17)
project(neojam C ASM)

set(CMAKE_C_STANDARD 99)

aux_source_directory(src/core VM_SRCS)
aux_source_directory(src/gcp VM_SRCS)
aux_source_directory(src/darwin_x86_64 VM_SRCS)

SET(VM_SRCS ${VM_SRCS} src/darwin_x86_64/darwin_callNative.S)

# dynamic libjvm
add_library(jvm SHARED ${VM_SRCS})

SET(VM_BIN src/main.c)
add_executable(java ${VM_BIN})

target_link_libraries(java pthread m z dl jvm)

# use jni
add_executable(j2 src/java.c)
target_link_libraries(j2 pthread m z dl jvm)