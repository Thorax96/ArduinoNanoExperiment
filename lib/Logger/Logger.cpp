#include "Logger.h"

Logger::Logger() {
    Serial.begin(baudRate);
}

void Logger::print(const String msg) {
    Serial.println(msg);
}
