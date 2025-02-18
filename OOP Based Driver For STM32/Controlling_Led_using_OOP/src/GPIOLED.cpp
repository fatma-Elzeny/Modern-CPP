#include "../include/GPIOLED.hpp"



Led::Led(uint32_t gpioBase, uint32_t pinNumber)
    : gpio(gpioBase, pinNumber, Gpio::OUTPUT) {}

void Led::turnOn() {
    gpio.setHigh();
}

void Led::turnOff() {
    gpio.setLow();
}

void Led::toggle() {
    gpio.toggle();
}
