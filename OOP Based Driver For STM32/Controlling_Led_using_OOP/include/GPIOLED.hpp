#ifndef LED_HPP
#define LED_HPP

#include "GPIO.hpp"

class Led {
private:
    Gpio gpio;

public:
    Led(uint32_t gpioBase, uint32_t pinNumber);
    void turnOn();
    void turnOff();
    void toggle();
};

#endif // LED_HPP

