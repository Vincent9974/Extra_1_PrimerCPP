#include "String2.h"
#include <cstring>
#include <iostream>

String::String()
{
    str = new char[1];
    str[0] = '\0';
}

String::String(const char *s)
{
    str = new char[strlen(s) + 1];
    strcpy(str,s);
}

String::String(const String &st)
{
    str = new char[strlen(st.str) + 1];
    strcpy(str,st.str);
}

String::~String() {}

String String::operator+(const String &st) const
{
    String result;
    delete[] result.str;
    result.str = new char[strlen(st.str) + 1];
    strcpy(result.str, str);
    strcat(result.str, st.str);
    return result;
}

String &String::operator=(const String &st)
{
    if(this == &st)
        return *this;
    delete[] str;
    str = new char[strlen(st.str) + 1];
    strcpy(str, st.str);
    return *this;
}



void String::Stringlow()
{
    for(int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}

void String::Stringup()
{
    for(int i = 0; i < strlen(str); i++)
    {
        str[i] = toupper(str[i]);
    }
}

int String::CharCount(char c) const
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

std::ostream &operator<<(std::ostream &os, const String &st)
{
    os << st.str;
    return os;
}

std::istream &operator>>(std::istream &is, String &st)
{
    const int MAX_LEN = 100;
    char temp[MAX_LEN];
    is.get(temp, MAX_LEN);

    if (is)
    {
        st.str = new char[strlen(temp) + 1];
        strcpy(st.str, temp);
    }

    while (is && is.get() != '\n')
    {
        continue;
    }

    return is;
}



String operator+(const String &st, const char *s)
{
    String result;
    int result_strLen = strlen(st.str) + strlen(s);
    result.str = new char[result_strLen + 1];
    strcpy(result.str, st.str);
    strcat(result.str, s);
    return result;
}

String operator+(const char *s, const String &st)
{
    String result;
    int result_strLen = strlen(st.str) + strlen(s);
    result.str = new char[result_strLen + 1];
    strcpy(result.str, s);
    strcat(result.str, st.str);
    return result;
}



bool operator==(const String &st1, const String &st2)
{
    return (strcmp(st1.str, st2.str) == 0);
}
