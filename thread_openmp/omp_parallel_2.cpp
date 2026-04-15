#include "omp_parallel_2.h"

#include <iostream>
#include <omp.h>

int omp_parallel_2()
{
    const int quantidade_de_threads = 12;
    omp_set_num_threads(quantidade_de_threads);

    #pragma omp parallel
    {
        int id_da_thread = omp_get_thread_num();
        std::cout << "Sou a thread " << id_da_thread << std::endl;
    }

    return 0;
}
