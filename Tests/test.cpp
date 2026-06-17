#include "StringIsomorphism.h"
#include <string>
#include <map>
#include <gtest/gtest.h>

// Тест 1. Строки разной длины
TEST(TestsForSolveIsomorphism, DifferentLengthsShouldFail) {
	std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("abc", "ab", mapping));
}

// Тест 2. Одиночные символы совпадают
TEST(TestsForSolveIsomorphism, SingleCharsShouldMatch) {
	std::map<char, char> mapping;
	EXPECT_TRUE(solveIsomorphism("a", "z", mapping));
}

// Тест 3. Идентичные строки
TEST(TestsForSolveIsomorphism, IdenticalStringsShouldMatch) {
	std::map<char, char> mapping;
	EXPECT_TRUE(solveIsomorphism("test", "test", mapping));
}

// Тест 4. Простое взаимо-однозначное соответствие
TEST(TestsForSolveIsomorphism, SimpleBijection) {
	std::map<char, char> mapping;
	EXPECT_TRUE(solveIsomorphism("abc", "def", mapping));
}

// Тест 5. Повторяющиеся символы с корректным соответствием
TEST(TestsForSolveIsomorphism, RepeatedCharsValidMapping) {
	std::map<char, char> mapping;
	EXPECT_TRUE(solveIsomorphism("egg", "add", mapping));
}

// Тест 6. Конфликт прямого соответствия 
// (один символ первой строки пытается отобразиться в два разных символа второй)
TEST(TestsForSolveIsomorphism, DirectMappingConflict) {
	std::map<char, char> mapping;
	EXPECT_FALSE(solveIsomorphism("foo", "bar", mapping));
}

// Тест 7. Конфликт обратного соответствия 
// (два разных символа первой строки пытаются отобразиться в один символ второй)
TEST(TestsForSolveIsomorphism, ReverseMappingConflict) {
	std::map<char, char> mapping;
	EXPECT_FALSE(solveIsomorphism("ab", "aa", mapping));
}

// Тест 8. Учёт регистра (заглавные и строчные буквы – разные символы)
TEST(TestsForSolveIsomorphism, CaseSensitiveMapping) {
	std::map<char, char> mapping;
	EXPECT_TRUE(solveIsomorphism("Aa", "Bb", mapping));
}

// Тест 9. Разрешённые специальные символы (точка и запятая)
TEST(TestsForSolveIsomorphism, SpecialCharsDotComma) {
	std::map<char, char> mapping;
	EXPECT_TRUE(solveIsomorphism("a.b,c", "x.y,z", mapping));
}

// Тест 10. Максимальная длина строк (100 символов)
TEST(TestsForSolveIsomorphism, MaxLengthStrings) {
	std::map<char, char> mapping;
    std::string str1(100, 'a');
    std::string str2(100, 'b');
	EXPECT_TRUE(solveIsomorphism(str1, str2, mapping));
}

// Тест 11. Сложная корректная биекция
TEST(TestsForSolveIsomorphism, ComplexValidBijection) {
	std::map<char, char> mapping;
	EXPECT_TRUE(solveIsomorphism("paper", "title", mapping));
}

// Тест 12. Пустые строки (граничный случай)
TEST(TestsForSolveIsomorphism, EmptyStrings) {
	std::map<char, char> mapping;
	EXPECT_TRUE(solveIsomorphism("", "", mapping));
}

// Тест 13. Только цифры
TEST(TestsForSolveIsomorphism, OnlyDigitsSuccess) {
    std::map<char, char> mapping;
    EXPECT_TRUE(solveIsomorphism("123", "456", mapping));
}

// Тест 14. Только заглавные буквы
TEST(TestsForSolveIsomorphism, OnlyUppercaseSuccess) {
    std::map<char, char> mapping;
    EXPECT_TRUE(solveIsomorphism("ABC", "XYZ", mapping));
}

// Тест 15. Комбинация букв, цифр и спец. символов
TEST(TestsForSolveIsomorphism, MixedCharsSuccess) {
    std::map<char, char> mapping;
    EXPECT_TRUE(solveIsomorphism("a1.b", "x2,y", mapping));
}

// Тест 16. Чередующиеся символы
TEST(TestsForSolveIsomorphism, AlternatingCharsSuccess) {
    std::map<char, char> mapping;
    EXPECT_TRUE(solveIsomorphism("abab", "xyxy", mapping));
}

// Тест 17. Все символы одинаковые
TEST(TestsForSolveIsomorphism, AllSameCharsSuccess) {
    std::map<char, char> mapping;
    EXPECT_TRUE(solveIsomorphism("aaaa", "bbbb", mapping));
}

// Тест 18. Палиндром
TEST(TestsForSolveIsomorphism, PalindromeSuccess) {
    std::map<char, char> mapping;
    EXPECT_TRUE(solveIsomorphism("racecar", "1234321", mapping));
}

// Тест 19. Строки длиной 2 символа, обратное отображение
TEST(TestsForSolveIsomorphism, ReverseMappingLength2) {
    std::map<char, char> mapping;
    EXPECT_TRUE(solveIsomorphism("ab", "ba", mapping));
}

// Тест 20. Прямой конфликт в конце строки
TEST(TestsForSolveIsomorphism, DirectConflictAtEnd) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("abca", "abcd", mapping));
}

// Тест 21. Прямой конфликт в середине строки
TEST(TestsForSolveIsomorphism, DirectConflictInMiddle) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("aab", "abc", mapping));
}

// Тест 22. Обратный конфликт в начале строки
TEST(TestsForSolveIsomorphism, ReverseConflictAtStart) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("ab", "cc", mapping));
}

// Тест 23. Обратный конфликт в середине строки
TEST(TestsForSolveIsomorphism, ReverseConflictInMiddle) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("abc", "xxy", mapping));
}

// Тест 24. Смешанный регистр
TEST(TestsForSolveIsomorphism, MixedCaseReverseConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("Aa", "bb", mapping));
}

// Тест 25. Только цифры
TEST(TestsForSolveIsomorphism, DigitsDirectConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("11", "12", mapping));
}

// Тест 26. Только спец. символы
TEST(TestsForSolveIsomorphism, SpecialCharsDirectConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("..", ".,", mapping));
}

// Тест 27. Только цифры, сложная биекция с повторами
TEST(TestsForSolveIsomorphism, DigitsComplexBijection) {
    std::map<char, char> mapping;
    EXPECT_TRUE(solveIsomorphism("1231", "4564", mapping));
}

// Тест 28. Комбинация символов с прямым конфликтом в конце
TEST(TestsForSolveIsomorphism, MixedCharsDirectConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("a1a", "b2c", mapping));
}

// Тест 29. Максимальная длина (100 символов), 
// повторяющиеся символы в обеих строках, в конце прямой конфликт
TEST(TestsForSolveIsomorphism, MaxLengthRepeatedChar) {
    std::map<char, char> mapping;
    std::string str1(99, 'a');
    str1 += 'c';
    std::string str2(100, 'b');
    EXPECT_FALSE(solveIsomorphism(str1, str2, mapping));
}

// Тест 30. Смешанный регистр и цифры c прямым конфликтом
TEST(TestsForSolveIsomorphism, MixedCaseDigitsDirectConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("A1A", "b2c", mapping));
}

// Тест 31. Смешанный регистр и цифры с обратным конфликтом
TEST(TestsForSolveIsomorphism, MixedCaseDigitsReverseConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("A1B", "b2b", mapping));
}

// Тест 32. Буквы и спец. символы с прямым конфликтом
TEST(TestsForSolveIsomorphism, LettersSpecialCharsDirectConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("a.b.a", "x,y,z", mapping));
}

// Тест 33. Буквы и спец. символы с обратным конфликтом
TEST(TestsForSolveIsomorphism, LettersSpecialCharsReverseConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("a.b,c", "x,y,y", mapping));
}

// Тест 34. Множественные прямые конфликты в одной строке
TEST(TestsForSolveIsomorphism, MultipleDirectConflicts) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("aabb", "xyzy", mapping));
}

// Тест 35. Множественные обратные конфликты в одной строке
TEST(TestsForSolveIsomorphism, MultipleReverseConflicts) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("abcd", "wxxx", mapping));
}

// Тест 36. Структура палиндрома с прямым конфликтом
TEST(TestsForSolveIsomorphism, PalindromeStructureDirectConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("abccba", "xyzzwv", mapping));
}

// Тест 37. Структура чередования с обратным конфликтом
TEST(TestsForSolveIsomorphism, AlternatingStructureReverseConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("abab", "xyxx", mapping));
}

// Тест 38. Цифры и спец. символы, сложный обратный конфликт
TEST(TestsForSolveIsomorphism, DigitsSpecialCharsComplexConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("1.2.", "abac", mapping));
}

// Тест 39. Заглавные буквы и спец. символы с прямым конфликтом
TEST(TestsForSolveIsomorphism, UppercaseSpecialCharsDirectConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("A.B.A", "1.2.3", mapping));
}

// Тест 40. Все типы символов (строчные, заглавные, цифры, спец. символы) с конфликтом в конце
TEST(TestsForSolveIsomorphism, AllCharTypesMixedReverseConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("aA1.", "bB2b", mapping));
}

// Тест 41. Длинная строка с корректной сложной биекцией
TEST(TestsForSolveIsomorphism, LongStringValidBijection) {
    std::map<char, char> mapping;
    EXPECT_TRUE(solveIsomorphism("abcdefghijabcdefghijabc", "qrstuvwxyzqrstuvwxyzqrs", mapping));
}

// Тест 42. Длинная строка с прямым конфликтом в конце
TEST(TestsForSolveIsomorphism, LongStringDirectConflict) {
    std::map<char, char> mapping;
    EXPECT_FALSE(solveIsomorphism("abcdefghijklmnopqrstuvwxyza", "abcdefghijklmnopqrstuvwxyzx", mapping));
}