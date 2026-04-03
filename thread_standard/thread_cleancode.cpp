#include "thread_cleancode.h"

#include <iostream>
#include <thread>

void printFirstThreadMessage()
{
    std::cout << "sou a thread 1!" << std::endl;
}

void printSecondThreadMessageWithParameter(int displayValue)
{
    std::cout << "sou a thread 2 com o parametro: " << displayValue << "!" << std::endl;
}

int thread_cleancode()
{
    std::cout << "criando e executando as threads..." << std::endl;

    std::thread firstWorkerThread(printFirstThreadMessage);
    std::thread secondWorkerThread(printSecondThreadMessageWithParameter, 2025);

    std::cout << "sou a main!" << std::endl;

    firstWorkerThread.join();
    secondWorkerThread.join();

    std::cout << "saindo..." << std::endl;

    return 0;
}

