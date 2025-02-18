#ifndef GPIO_HPP
#define GPIO_HPP

#include <cstdint>

// RCC Base Address & AHB1ENR Register (Clock Enable)
#define RCC_BASE       0x40023800
#define RCC_AHB1ENR    (*(volatile uint32_t*)(RCC_BASE + 0x30))

// GPIO Base Addresses
#define GPIOA_BASE  0x40020000
#define GPIOB_BASE  0x40020400
#define GPIOC_BASE  0x40020800

class Gpio {
private:
    volatile uint32_t* MODER;
    volatile uint32_t* ODR;
    volatile uint32_t* BSRR;
    uint32_t pin;

public:
    enum Mode { INPUT = 0, OUTPUT = 1, ALT = 2, ANALOG = 3 };

    Gpio(uint32_t gpioBase, uint32_t pinNumber, Mode mode);
    void setHigh();
    void setLow();
    void toggle();
};

#endif // GPIO_HPP
