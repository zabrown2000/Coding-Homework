#ifndef CODEFORCHAR_H
#define CODEFORCHAR_H

#include <string>

class CodeForChar
{
public: //making public so tree class can access it
    char letterToCode;
    std::string code;

    CodeForChar(char letter, std::string code);
    friend bool operator<(const CodeForChar& a, const CodeForChar& b);
};

#endif // !CODEFORCHAR_H



