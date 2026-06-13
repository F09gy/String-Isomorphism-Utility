#pragma once
#include <string>
#include <map>
#include <vector>

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

bool solveIsomorphism(const std::string& str1, const std::string& str2, std::map<char, char>& mapping);
bool readInputFile(const std::string& path, std::vector<std::string>& lines);
bool writeOutputFile(const std::string& path, bool isIsomorphic, const std::map<char, char>& mapping);