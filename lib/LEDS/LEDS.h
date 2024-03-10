#ifndef LEDS_h
#define LEDS_h  

#include <Logger.h>
#include <Tools.h>
#include <Constants.h>
#include <Arduino.h>
#include <string.h>
// Forward declaration of Logger class
class Logger;

class LEDS {
private:
    const int* LEDS_PORT = new int[1]{13};
    const int LEDS_PORT_SIZE = sizeof(LEDS_PORT) / sizeof(LEDS_PORT[0]);
    Logger* logger;

public:
    LEDS(Logger* _logger);
    void blink(const int port, const int lightingTimeMS);
    void blink(const int lightingTimeMS);
    int* getPortIds();

private:
    void init();
    int mapIdToPort(const int id);
    String getLedMsg(const int portId, const Constants::OnfOffOptions onOff);
    void turnOn(const int port);
    void turnOff(const int port);
};

#endif
