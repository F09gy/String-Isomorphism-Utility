#include "StringIsomorphism.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

/**
 * \brief Функция чтения входного файла
 * \param[in] path - путь к входному файлу
 * \param[out] lines - ссылка на вектор для сохранения прочитанных строк
 * \return - true если файл успешно прочитан, иначе false
 */
bool readInputFile(std::string path, std::vector<std::string>& lines)
{
    std::ifstream file(path);

    if (!file.is_open())
    {
        return false;
    }

    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    return true;
}

/**
* \brief Проверяет изоморфность двух строк и формирует словарь символьных соответствий
* \param[in] str1 - первая входная строка
* \param[in] str2 - вторая входная строка
* \param[out] mapping - ссылка на std::map для записи правил перевода (char1 -> char2)
* \return - true, если строки изоморфны; false, если не изоморфны (длины не равны или нарушена биективность)
*/
bool solveIsomorphism(std::string str1, std::string str2, std::map<char, char>& mapping)
{
    if (str1.length() != str2.length())
    {
        return false;
    }

    for (size_t i = 0; i < str1.length(); ++i)
    {
        char c1 = str1[i];
        char c2 = str2[i];

        auto it = mapping.find(c1);

        if (it != mapping.end())
        {
            if (it->second != c2)
            {
                return false;
            }
        }
        else
        {
            auto valueIt = std::find_if(mapping.begin(), mapping.end(),
                [c2](const std::pair<char, char>& p)
                {
                    return p.second == c2;
                });

            if (valueIt != mapping.end())
            {
                return false;
            }

            mapping[c1] = c2;
        }
    }

    return true;
}

/**
 * \brief Функция записи результата в выходной файл
 * \param path[in] - путь к выходному файлу
 * \param isIsomorphic[in] - флаг изоморфности строк
 * \param mapping[in, out] - словарь соответствий (может быть пустым)
 * \return - true если файл успешно записан, иначе false
 */
bool writeOutputFile(std::string path, bool isIsomorphic, const std::map<char, char>& mapping)
{

}