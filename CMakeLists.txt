cmake_minimum_required(VERSION 3.8)
project(HW3)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c phoneBook.c phoneBook.h colors.h strhlp.c strhlp.h)
add_executable(HW3 ${SOURCE_FILES})