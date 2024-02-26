#include <iostream>
#include <cstring>

class ABC {
private:
    char* label;
    int rating;

public:
    ABC(const char* l = "null", int r = 0);
    ABC(const ABC& a);
    virtual ~ABC();
    ABC& operator=(const ABC& a);
    virtual void View() const = 0;
};


class baseDMA: public ABC
{
public:
    baseDMA(const char* l = "null", int r = 0);
    virtual ~ baseDMA();
    virtual void View() const override;
};

class lacksDMA : public ABC {
private:
    char* color;

public:
    lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
    ~lacksDMA() override;
    void View() const override;
};

