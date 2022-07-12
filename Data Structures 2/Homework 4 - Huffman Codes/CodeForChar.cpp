#include "CodeForChar.h"

CodeForChar::CodeForChar(char letter, std::string code) : letterToCode(letter), code(code) {}

/**
 * Comparator for list sorting function.
 * 
 */
bool operator<(const CodeForChar& a, const CodeForChar& b)
{
    return a.letterToCode < b.letterToCode;
}
