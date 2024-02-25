// String2.h
#ifndef STRING2_H_
#define STRING2_H_

#include <iostream>

class String {
private:
    char* str;
public:
    String();
    String(const char* s);
    String(const String& st);
    ~String();

    String operator+(const String& st) const;
    String& operator=(const String& st);
    


    void Stringlow();
    void Stringup();
    int CharCount(char c) const;
    



    friend std::ostream& operator<<(std::ostream& os, const String& st);
    friend std::istream& operator>>(std::istream& is, String& st);
    friend String operator+(const String & st, const char * s);
    friend String operator+(const char * s, const String & st);
    friend bool operator==(const String & st1, const String & st2);
};

#endif
