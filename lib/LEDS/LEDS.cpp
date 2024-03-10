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

void LEDS::turnOn(const int port){
    const int p = mapIdToPort(port);

    digitalWrite(p, HIGH);
    logger->print(getLedMsg(port, Constants::ON));
}

void LEDS::turnOff(const int port){
    const int p = mapIdToPort(port);

    digitalWrite(p, HIGH);
    logger->print(getLedMsg(port, true));
}

void LEDS::blink(const int lightingTimeMS){
    const int* ports = getPortIds();
    Tools::forEach(ports, [this](const int port) { turnOn(port); }); // Using lambda function
    delay(lightingTimeMS);
    Tools::forEach(ports, [this](const int port) { turnOff(port); }); // Using lambda function
}

void LEDS::blink(const int port, const int lightingTimeMS) {
    const int p = mapIdToPort(port);

    digitalWrite(p, HIGH);
    logger->print(getLedMsg(port, Constants::ON));
    delay(lightingTimeMS);
    digitalWrite(p, LOW);
    logger->print(getLedMsg(port, Constants::OFF));
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

String LEDS::getLedMsg(const int portId, const Constants::OnfOffOptions onOff){
    const String onOffStr = onOff.getValue() 
        ? Constants::on 
        : Constants::off;
    const String portIdStr = String(portId);

    return "LED " + portIdStr + " has been turned " + onOffStr + ".";
}

