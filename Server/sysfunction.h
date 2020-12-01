#ifndef SYSFUNCTION_H
#define SYSFUNCTION_H

#include <iostream>
#include <iomanip>

template <typename T>
void getnumber(T& number, const char* message)
{
    bool isCorrect;

    do
    {
        isCorrect = true;
        std::cout << message;
        std::cin >> std::setw(20) >> number;
        if (std::cin.fail())
        {
            isCorrect = false;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Invalid number. Try again." << std::endl;
        }
        else
        {
             std::cin.ignore(32767, '\n');
        }
    } while (!isCorrect);
}

#endif // SYSFUNCTION_H