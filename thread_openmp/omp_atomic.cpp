#include "omp_atomic.h"

#include <omp.h>
#include <iostream>

int omp_atomic(int argc, char *argv[])
{
    int limite_interacoes, soma_acumulada;

    if (argc < 2)
    {
        return -1;
    }

    limite_interacoes = atoi(argv[1]);
    soma_acumulada = 0;

    std::cout << "Iniciando! - N: " << limite_interacoes << std::endl << std::endl;

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < limite_interacoes; i++)
    {
        for (int j = 0; j < limite_interacoes; j++)
        {
            #pragma omp atomic
            soma_acumulada = soma_acumulada + (i * j);
        }
    }

    std::cout << "Finalizando! - Sum: " << soma_acumulada << std::endl;

    return 0;
}
