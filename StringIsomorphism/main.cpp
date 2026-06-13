#include "StringIsomorphism.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Ошибка ввода: аргументов меньше или больше, чем 2." << std::endl;
        return static_cast<int>(ErrorCode::ERR_ARGS_COUNT);
    }

    std::string inputPath = argv[1];
    std::string outputName = argv[2];
}