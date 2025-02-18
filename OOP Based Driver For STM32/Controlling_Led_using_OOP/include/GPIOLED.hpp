#ifndef GPIO_LED_HPP
#define GPIO_LED_HPP

#include <cstdint>

#define RCC_BASE       0x40023800
#define RCC_AHB1ENR    (*(volatile uint32_t*)(RCC_BASE + 0x30))

class GpioLed {
private:
    volatile uint32_t* MODER;
    volatile uint32_t* ODR;
    volatile uint32_t* BSRR;
    uint32_t pin;

public:
    GpioLed(uint32_t gpioBase, uint32_t pinNumber);
    void turnOn();
    void turnOff();
    void toggle();
};

#endif // GPIO_LED_HPP
