#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>

class Constants{
    public:
        class OnfOffOptions {
        public:
            OnfOffOptions(bool onOff) : value(onOff) {}
            bool getValue() const { return value; }
        private:
            bool value;
        };

        static const OnfOffOptions ON;
        static const OnfOffOptions OFF;
        static const String on;
        static const String off;
};

#endif