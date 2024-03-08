#include "LEDS.h"

LEDS::LEDS(Logger* _logger) {
    logger = _logger;
    init();
}

void LEDS::init() {
    for(int i = 0; i < LEDS_PORT_SIZE; i++){
        pinMode(LEDS_PORT[i], OUTPUT);
    }
}

void LEDS::blink(const int port, const int lightingTimeMS) {
    const int p = mapIdToPort(port);

    digitalWrite(p, HIGH);
    delay(lightingTimeMS);
    logger->print(getLedMsg(port, true));
    digitalWrite(p, LOW);
    logger->print(getLedMsg(port, false));
}

int* LEDS::getPortIds() {
    int* ids = new int[LEDS_PORT_SIZE];

    for(int i = 0; i < LEDS_PORT_SIZE; i++){
        ids[i] = i;
    }

    return ids;
}

int LEDS::mapIdToPort(const int id) {
    if(LEDS_PORT_SIZE < id){
        return LEDS_PORT[(LEDS_PORT_SIZE - 1)];
    }

    return LEDS_PORT[id];
}

String LEDS::getLedMsg(const int portId, const bool onOff){
    const String onOffStr = onOff ? "on" : "off";
    const String portIdStr = String(portId);

    return "LED " + portIdStr + " has been turned " + onOffStr + ".";
}
