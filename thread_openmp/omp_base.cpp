#include <omp.h>
#include <iostream>

int omp_base()
{
    const int quantidade_de_threads = 5;
    const int tamanho_do_array = 100;
    int resultados[tamanho_do_array];

    #pragma omp parallel num_threads(quantidade_de_threads)
    {
        int id_da_thread = omp_get_thread_num();

        if (id_da_thread == 0)
        {
            std::cout << "Executando thread mestre: " << id_da_thread << std::endl;
            std::cout << omp_get_num_threads() << " threads em operacao!" << std::endl;
        }
        else
        {
            std::cout << "Executando thread worker: " << id_da_thread << std::endl;
        }

        #pragma omp for
        for (int indice = 0; indice < tamanho_do_array; indice++)
        {
            resultados[indice] = omp_get_thread_num() * indice;
        }

        #pragma omp master
        for (int indice = 0; indice < tamanho_do_array; indice++)
        {
            std::cout << "a[" << indice << "] = " << resultados[indice] << std::endl;
        }
    }

    return 0;
}