#include "incryption.h"
#include <cctype>
#include <cstdint>

VigenereCipher::VigenereCipher()
{
    for (uint32_t i = 0; i < MAX_SYM; i++)
    {
        uint32_t letter;
        if (i < 10) letter = i + '0';
        else letter = i + '0' + 7;

        for (uint32_t j = 0; j < MAX_SYM; j++)
        {
            if (letter == ':') letter = 'A';
            if (letter > 'Z')  letter = '0';
            matrix[i][j] =  letter++;
        }
    }
}

void VigenereCipher::incrypt(const std::string& keyword, std::string& message)
{
    int key, source;
    for (uint32_t i = 0, j = 0; i < static_cast<uint32_t>(message.size()); i++, j++)
    {
        if (j == static_cast<uint32_t>(keyword.size())) j = 0;

        if (keyword[j] <= '9') key = keyword[j] - 48;
        else key = keyword[j] - 55;

        if (message[i] <= '9') source = toupper(message[i]) - 48;
        else source = toupper(message[i]) - 55;

        if (message[i] != ' ') message[i] = matrix[key][source];
        else j--;
    }
}

void VigenereCipher::decrypt(const std::string& keyword, std::string& message)
{
    int key;
    for (uint32_t i = 0, j = 0; i < static_cast<uint32_t>(message.size()); i++, j++)
    {
        if (j == static_cast<uint32_t>(keyword.size())) j = 0;

        if (keyword[j] <= '9')
            key = keyword[j] - 48;
        else
            key = keyword[j] - 55;

        if (message[i] != ' ')
        {
            message[i] = findLetter(key, message[i]);
        }
        else
        {
            message[i] = ' ';
            j--;
        }
    }

    for (uint32_t i = 0; i < message.size(); i++)
    {
        message[i] = tolower(message[i]);
    }
}

char VigenereCipher::findLetter(uint32_t j, char sym)
{
    for(uint32_t i = 0; i < Z; i++) {
        if (matrix[j][i] == static_cast<uint32_t>(sym))
        {
            if (i <= 9)
                return i + 48;
            else return i + 55;
        }
    }
   std::exit(-1);
}
