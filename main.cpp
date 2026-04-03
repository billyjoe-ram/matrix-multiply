#include <iostream>
#include <chrono>
#include <iomanip>

#include "matrix/matrix.h"
// #include "matrix_cleancode.h"
//#include "thread.h"
//#include "thread_cleancode.h"
#include "parallel_matrix/matrix_parallel.h"

void printTime(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point current) {
    long long diff = std::chrono::duration_cast<std::chrono::milliseconds>(current - start).count();

    long long h = diff / 3600000;
    long long m = (diff % 3600000) / 60000;
    long long s = (diff % 60000) / 1000;
    long long ms = diff % 1000;

    std::cout << h << ":" << m << ":" << s << ":" << ms;
}

int main(int argc, char *argv[]) {
    std::chrono::steady_clock::time_point programStart = std::chrono::steady_clock::now();

    std::cout << "[SEQUENTIAL] Start: 0:0:0:0 | Time spent: 0:0:0:0" << std::endl;

    std::chrono::steady_clock::time_point startSeq = std::chrono::steady_clock::now();
    matrix(argc, argv);
    std::chrono::steady_clock::time_point endSeq = std::chrono::steady_clock::now();

    std::cout << "[SEQUENTIAL] End: ";
    printTime(programStart, endSeq);
    std::cout << " | Total time: ";
    printTime(startSeq, endSeq);
    std::cout << std::endl << "--------------------------------" << std::endl;

    std::cout << "[PARALLEL] Start: ";
    printTime(programStart, std::chrono::steady_clock::now());
    std::cout << " | Time spent : 0:0:0:0" << std::endl;

    std::chrono::steady_clock::time_point startPar = std::chrono::steady_clock::now();
    matrix_parallel(argc, argv);
    std::chrono::steady_clock::time_point endPar = std::chrono::steady_clock::now();

    std::cout << "[PARALLEL] End: ";
    printTime(programStart, endPar);
    std::cout << " | Total time: ";
    printTime(startPar, endPar);
    std::cout << std::endl;

    return 0;
}
