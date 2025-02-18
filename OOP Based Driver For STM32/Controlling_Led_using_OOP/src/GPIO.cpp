#include "../include/GPIO.hpp"

Gpio::Gpio(uint32_t gpioBase, uint32_t pinNumber, Mode mode)
    : pin(pinNumber) {
    
    MODER = (volatile uint32_t*)(gpioBase + 0x00);
    ODR = (volatile uint32_t*)(gpioBase + 0x14);
    BSRR = (volatile uint32_t*)(gpioBase + 0x18);

    // Enable GPIO Clock
    if (gpioBase == GPIOA_BASE) RCC_AHB1ENR |= (1 << 0);
    if (gpioBase == GPIOB_BASE) RCC_AHB1ENR |= (1 << 1);
    if (gpioBase == GPIOC_BASE) RCC_AHB1ENR |= (1 << 2);

    // Set Mode (2 bits per pin)
    *MODER &= ~(3 << (pin * 2)); // Clear bits
    *MODER |= (mode << (pin * 2)); // Set mode
}

void Gpio::setHigh() {
    *BSRR = (1 << pin);
}

void Gpio::setLow() {
    *BSRR = (1 << (pin + 16));
}

void Gpio::toggle() {
    *ODR ^= (1 << pin);
}
