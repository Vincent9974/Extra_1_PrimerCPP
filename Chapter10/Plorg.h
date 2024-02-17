#pragma once

class Plorg
{
private:
    static const int MAX_NAME_LENGTH = 19;
    char name[MAX_NAME_LENGTH + 1];  // +1 for null terminator
    int satisfactionIndex;

public:
    Plorg(const char* n = "Plorga", int ci = 50);
    void setSatisfactionIndex(int ci);
    void report() const;
};