#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

enum class ErrorCode
{
    SUCCESS,
    ERR_ARGS_COUNT, 
    ERR_INPUT_FILE_NOT_FOUND, 
    ERR_OUTPUT_FILE_CREATE, 
    ERR_INVALID_CHARS, 
    ERR_LINE_LENGTH, 
    ERR_READ
};

// Функция чтения входного файла
bool readInputFile(std::string path, std::vector<std::string>& lines)
{

}

// Функция проверки изоморфности
bool solveIsomorphism(std::string str1, std::string str2, std::map<char, char>& mapping)
{

}

// Функция создания файла и записи результата
bool writeOutputFile(std::string path, bool isIsomorphic, const std::map<char, char>& mapping)
{

}

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
