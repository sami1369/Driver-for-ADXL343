
#include "utils.h"

uint32_t generateRandomNumber(uint32_t start, uint32_t end)
{
    cout << "Random numbers between start and end:\n";
    // Generate a random number between start and end
    uint32_t randomNumber = start + rand() % (end - start + 1);
    cout << randomNumber << std::endl;
    return randomNumber;
}