#include "omp_reduction.h"

#include <omp.h>
#include <iostream>

int omp_reduction(int argc, char *argv[])
{
    int limite_calculo, soma_total;

    if (argc < 2)
    {
        return -1;
    }

    limite_calculo = atoi(argv[1]);
    soma_total = 0;

    std::cout << "Iniciando! - N: " << limite_calculo << std::endl << std::endl;

    #pragma omp parallel for collapse(2) reduction(+:soma_total)
    for (int i = 0; i < limite_calculo; i++)
    {
        for (int j = 0; j < limite_calculo; j++)
        {
            soma_total = soma_total + (i * j);
        }
    }

    std::cout << "Finalizando! - Sum: " << soma_total << std::endl;

    return 0;
}
