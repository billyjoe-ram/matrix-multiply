cmake_minimum_required(VERSION 3.27)
project(MultiplicacaoMatrizes)

set(CMAKE_CXX_STANDARD 11)

add_executable(MultiplicacaoMatrizes main.cpp
        thread_standard/thread.cpp
        thread_standard/thread.h
        thread_standard/thread_cleancode.cpp
        thread_standard/thread_cleancode.h
        matrix/matrix.cpp
        matrix/matrix.h
        matrix/matrix_cleancode.cpp
        matrix/matrix_cleancode.h
        parallel_matrix/matrix_parallel.cpp
        parallel_matrix/matrix_parallel.h
        thread_openmp/omp_base.cpp
        thread_openmp/omp_base.h)
