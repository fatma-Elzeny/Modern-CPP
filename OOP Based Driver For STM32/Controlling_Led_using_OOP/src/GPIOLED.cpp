#include "../include/GPIOLED.hpp"

GpioLed::GpioLed(uint32_t gpioBase, uint32_t pinNumber)
    : pin(pinNumber) {
    
    // Calculate register addresses based on GPIO base
    MODER = (volatile uint32_t*)(gpioBase + 0x00);
    ODR = (volatile uint32_t*)(gpioBase + 0x14);
    BSRR = (volatile uint32_t*)(gpioBase + 0x18);

    // Enable GPIO clock in RCC
    if (gpioBase == 0x40020000) RCC_AHB1ENR |= (1 << 0); // GPIOA
    if (gpioBase == 0x40020400) RCC_AHB1ENR |= (1 << 1); // GPIOB
    if (gpioBase == 0x40020800) RCC_AHB1ENR |= (1 << 2); // GPIOC

    // Configure as output (MODER: 2 bits per pin)
    *MODER &= ~(3 << (pin * 2)); // Clear
    *MODER |= (1 << (pin * 2));  // Set to output mode
}

void GpioLed::turnOn() {
    *BSRR = (1 << pin);
}

void GpioLed::turnOff() {
    *BSRR = (1 << (pin + 16));
}

void GpioLed::toggle() {
    *ODR ^= (1 << pin);
}
