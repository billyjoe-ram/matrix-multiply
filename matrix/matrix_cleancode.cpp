#include "matrix_cleancode.h"

#include <iostream>
#include <cstdlib>

int matrix_cleancode(int argc, char *argv[]) {

    int matrixDimension;
    float **matrixA, **matrixB, **resultMatrix;

    if(argc < 2) return -1;
    matrixDimension = atoi(argv[1]);

    matrixA = new float*[matrixDimension];
    matrixB = new float*[matrixDimension];
    resultMatrix = new float*[matrixDimension];

    for(int i = 0; i < matrixDimension; i++)
    {
        matrixA[i] = new float[matrixDimension];
        matrixB[i] = new float[matrixDimension];
        resultMatrix[i] = new float[matrixDimension];
    }

    for(int i = 0; i < matrixDimension; i++) {
        for(int j = 0; j < matrixDimension; j++)
        {
            matrixA[i][j] = i + 1;
            matrixB[i][j] = (i + 1) + (j + 1);
            resultMatrix[i][j] = 0.0;
        }
    }

    for (int i = 0; i < matrixDimension; i++) {
        for (int j = 0; j < matrixDimension; j++)
        {
            resultMatrix[i][j] = 0.0;
            for (int k = 0; k < matrixDimension; k++) {
                resultMatrix[i][j] = resultMatrix[i][j] + matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    for(int i = 0; i < matrixDimension; i++) {
        for(int j = 0; j < matrixDimension; j++) {
            std::cout << resultMatrix[i][j] << ", ";
        }

        std::cout << std::endl;
    };

    return 0;
}
