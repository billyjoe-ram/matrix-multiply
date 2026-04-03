#include "matrix_parallel.h"

#include <iostream>
#include <cstdlib>
#include <thread>

int matrixDimension;
float** matrixA;
float** matrixB;
float** resultMatrix;

void initializeMatrixA() {
    matrixA = new float*[matrixDimension];
    for (int i = 0; i < matrixDimension; i++) {
        matrixA[i] = new float[matrixDimension];
        for (int j = 0; j < matrixDimension; j++) {
            matrixA[i][j] = i + 1.0f;
        }
    }
}

void initializeMatrixB() {
    matrixB = new float*[matrixDimension];

    for (int i = 0; i < matrixDimension; ++i) {
        matrixB[i] = new float[matrixDimension];
    }

    for (int i = 0; i < matrixDimension; i++) {
        for (int j = 0; j < matrixDimension; j++) {
            matrixB[j][i] = (i + 1.0f) + (j + 1.0f);
        }
    }
}

void calculateRows(int startRow, int endRow) {
    for (int i = startRow; i < endRow; ++i) {
        resultMatrix[i] = new float[matrixDimension];
        for (int j = 0; j < matrixDimension; ++j) {
            float soma = 0.0f;
            for (int k = 0; k < matrixDimension; ++k) {
                soma += matrixA[i][k] * matrixB[j][k];
            }
            resultMatrix[i][j] = soma;
        }
    }
}

int matrix_parallel(int argc, char *argv[]) {
    if (argc < 2) return -1;

    matrixDimension = std::atoi(argv[1]);

    std::thread threadA(initializeMatrixA);
    std::thread threadB(initializeMatrixB);

    resultMatrix = new float*[matrixDimension];

    threadA.join();
    threadB.join();

    constexpr int numThreads = 4;
    std::thread calcThreads[numThreads];
    int rowsPerThread = matrixDimension / numThreads;

    for (int threadNo = 0; threadNo < numThreads; ++threadNo) {
        int start = threadNo * rowsPerThread;

        int end = (threadNo == (numThreads - 1)) ? matrixDimension : (threadNo + 1) * rowsPerThread;

        calcThreads[threadNo] = std::thread(calculateRows, start, end);
    }

    for (int t = 0; t < 4; t++) {
        calcThreads[t].join();
    }

    for (int i = 0; i < matrixDimension; i++) {
        for (int j = 0; j < matrixDimension; j++) {
            std::cout << resultMatrix[i][j] << ", ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < matrixDimension; i++) {
        delete[] matrixA[i];
        delete[] matrixB[i];
        delete[] resultMatrix[i];
    }
    delete[] matrixA;
    delete[] matrixB;
    delete[] resultMatrix;

    return 0;
}
