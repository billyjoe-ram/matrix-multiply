#include "omp_parallel_1.h"

#include <iostream>
#include <omp.h>

int omp_parallel_1()
{
    const int quantidade_de_threads = 12;
    omp_set_num_threads(quantidade_de_threads);

    #pragma omp parallel
    {
        int id_da_thread = omp_get_thread_num();
        printf("Sou a thread %i \n", id_da_thread);
    }

    return 0;
}
