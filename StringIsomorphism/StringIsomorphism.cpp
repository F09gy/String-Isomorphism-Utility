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
    // Попытаться открыть файл по указанному пути в режиме чтения
    std::ifstream file(path);

    // Если файл не открылся
    if (!file.is_open())
    {
        // Вернуть ложь
        return false;
    }

    // Прочитать содержимое файла построчно, добавляя каждую строку в массив (вектор lines)
    std::string line;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    // Вернуть истину
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
    // Проверить равенство длин обеих строк
    // Если длины строк не совпадают
    if (str1.length() != str2.length())
    {
        // Вернуть “не изоморфны”
        return false;
    }

    // Для каждого символа в строках
    for (size_t i = 0; i < str1.length(); ++i)
    {
        // Получить текущий символ из первой строки
        char c1 = str1[i];
        // Получить текущий символ из второй строки
        char c2 = str2[i];

        // Проверить наличие символа из первой строки в словаре
        auto it = mapping.find(c1);

        // Если символ из первой строки уже есть в словаре
        if (it != mapping.end())
        {
            // Сравнить сохранённое значение с символом второй строки
            // Если значения не совпадают
            if (it->second != c2)
            {
                // Вернуть “не изоморфны”
                return false;
            }
        }
        // Если символа из первой строки нет в словаре
        else
        {
            // Проверить, является ли символ из второй строки уже значением для любого другого правила в словаре
            auto valueIt = std::find_if(mapping.begin(), mapping.end(),
                [c2](const std::pair<char, char>& p)
                {
                    return p.second == c2;
                });
            
            // Если символ из второй строки уже используется
            if (valueIt != mapping.end())
            {
                // Вернуть “не изоморфны”
                return false;
            }

            // Если символ из второй строки свободен
            // Добавить пару в словарь
            mapping[c1] = c2;
        }
    }

    // Если цикл завершён без конфликтов
    // Вернуть “изоморфны”
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
    // Попытаться создать и открыть файл по указанному пути в режиме записи
    std::ofstream file(path);

    // Если файл не создан или не открыт
    if (!file.is_open())
    {
        // Вернуть ложь
        return false;
    }

    // Проверить флаг isIsomorphic
    // Если строки изоморфны
    if (isIsomorphic)
    {
        // Записать в файл строку «Изоморфны» и символ переноса строки
        file << "Изоморфны\n";

        // Для каждого ключа в словаре соответствий
        for (const auto& pair : mapping)
        {
            // Сформировать строку вида «(символ 1 -> символ 2)»
            // Записать сформированную строку в файл с переносом строки
            file << '(' << pair.first << ' ' << pair.second << ")\n";
        }
    }
    // Если строки не изоморфны
    else
    {
        // Записать в файл строку «Не изоморфны»
        file << "Не изоморфны\n";
    }

    // Закрыть файл
    file.close();

    // Вернуть истину
    return true;
}