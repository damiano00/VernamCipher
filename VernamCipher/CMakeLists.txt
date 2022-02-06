cmake_minimum_required(VERSION 3.19)
project(VernamCipher C)

set(CMAKE_C_STANDARD 11)

add_executable(bvernan main.c bvernan.c bvernan.h)