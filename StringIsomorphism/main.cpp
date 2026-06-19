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
    std::string outputPath = argv[2];
    std::vector<std::string> lines;
    if (!readInputFile(inputPath, lines))
    {
        std::cerr << "Ошибка чтения файла: " << inputPath << "\n";
        return static_cast<int>(ErrorCode::ERR_READ);
    }

    if (lines.size() < 2)
    {
        std::cerr << "Содержание указанного файла меньше двух строк\n";
        return static_cast<int>(ErrorCode::ERR_LINE_LENGTH);
    }

    if (lines.size() > 2)
    {
        std::cerr << "Содержание указанного файла больше двух строк\n";
        return static_cast<int>(ErrorCode::ERR_LINE_LENGTH);
    }

    std::string str1 = lines[0];
    std::string str2 = lines[1];

    if (str1.length() < 1 || str1.length() > 100)
    {
        std::cerr << "В одной из строк количество символов выходит за границы допустимого\n";
        return static_cast<int>(ErrorCode::ERR_LINE_LENGTH);
    }

    if (str2.length() < 1 || str2.length() > 100)
    {
        std::cerr << "В одной из строк количество символов выходит за границы допустимого\n";
        return static_cast<int>(ErrorCode::ERR_LINE_LENGTH);
    }

    for (char c : str1)
    {
        if (!(std::isalpha(static_cast<unsigned char>(c)) ||
            std::isdigit(static_cast<unsigned char>(c)) ||
            c == '.' ||
            c == ','))
        {
            std::cerr << "Содержание указанного файла имеет запрещённые символы\n";
            return static_cast<int>(ErrorCode::ERR_INVALID_CHARS);
        }
    }

    for (char c : str2)
    {
        if (!(std::isalpha(static_cast<unsigned char>(c)) ||
            std::isdigit(static_cast<unsigned char>(c)) ||
            c == '.' ||
            c == ','))
        {
            std::cerr << "Содержание указанного файла имеет запрещённые символы\n";
            return static_cast<int>(ErrorCode::ERR_INVALID_CHARS);
        }
    }

    std::map<char, char> mapping;

    bool isIsomorphic = solveIsomorphism(str1, str2, mapping);

    if (isIsomorphic)
    {
        if (!writeOutputFile(outputPath, isIsomorphic, mapping))
        {
            std::cerr << "Не получилось создать или открыть выходной файл\n";
            return static_cast<int>(ErrorCode::ERR_OUTPUT_FILE_CREATE);
        }
    }
    else
    {
        if (!writeOutputFile(outputPath, isIsomorphic, mapping))
        {
            std::cerr << "Не получилось создать или записать выходной файл\n";
            return static_cast<int>(ErrorCode::ERR_OUTPUT_FILE_CREATE);
        }
    }
    return static_cast<int>(ErrorCode::SUCCESS);
}