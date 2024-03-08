#ifndef Logger_h
#define Logger_h

#include <Arduino.h>

class Logger{
    public:
        Logger();
        void print(const String msg);
    private:
        const int baudRate = 9600;
};

#endif