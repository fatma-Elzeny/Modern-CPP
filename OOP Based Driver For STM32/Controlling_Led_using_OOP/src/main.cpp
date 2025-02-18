#include "../include/GPIOLED.hpp"


#define GPIOB_BASE  0x40020400  // GPIOB base address

Led led(GPIOB_BASE, 0);  // LED on PB0

int main() {
    while (1) {
        led.toggle();
        for (volatile int i = 0; i < 500000; i++); // Delay
    }
}
