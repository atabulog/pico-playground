#include "pico/stdlib.h"
#include <stdio.h>

int main()
{
    stdio_init_all();

    const uint LED_PIN = PICO_DEFAULT_LED_PIN; // Or 25 for Pico, or specific pin for Pico W LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true)
    {
        printf("Hello, world!\n");
        gpio_put(LED_PIN, 1); // Turn LED on
        sleep_ms(500);        // Wait 500ms
        gpio_put(LED_PIN, 0); // Turn LED off
        sleep_ms(500);        // Wait 500ms
    }
}
