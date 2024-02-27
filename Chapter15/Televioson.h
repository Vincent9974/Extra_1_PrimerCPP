#pragma once
#include <iostream>

class Remote;

class Tv
{
private:
    bool isOn;
    int volume;
    int channel;

public:
    Tv() : isOn(false), volume(5), channel(2) {}
    void powerOn() { isOn = !isOn; }
    void volumeUp()
    {
        if (isOn)
            volume++;
    }
    void volumeDown()
    {
        if (isOn && volume > 0)
            volume--;
    }
    void channelUp()
    {
        if (isOn)
            channel++;
    }
    void channelDown()
    {
        if (isOn && channel > 0)
            channel--;
    }
    void settings() const;
    void switchRemoteMode(Remote &r);
};

void Tv::settings() const
{
    std::cout << "TV is " << (isOn ? "On" : "Off") << std::endl;
    if (isOn)
    {
        std::cout << "Volume: " << volume << std::endl;
        std::cout << "Channel: " << channel << std::endl;
    }
}

class Remote
{
private:
    bool isInteractiveMode;

public:
    Remote() : isInteractiveMode(false) {}
    friend class Tv; // Tv is a friend of Remote
    void toggleMode() { isInteractiveMode = !isInteractiveMode; }
    void displayMode() const;
};

inline void Tv::switchRemoteMode(Remote &r)
{
    if (isOn)
    {
        r.toggleMode();
        std::cout << "Remote mode switched" << std::endl;
    }
    else
    {
        std::cout << "Turn on the TV before switching remote mode" << std::endl;
    }
}


// Remote member function definition
void Remote::displayMode() const {
    std::cout << "Remote is in " << (isInteractiveMode ? "Interactive" : "Normal") << " mode" << std::endl;
}