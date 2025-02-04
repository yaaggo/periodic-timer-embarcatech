#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#include "include/led.h"

volatile uint8_t led_index = 0;

uint8_t leds_routine[] = {
    LED_RED_PIN,
    LED_YELLOW_PIN,
    LED_GREEN_PIN
};

char *cores[] = {
    "vermelho",
    "amarelo",
    "verde"
};

bool traffic_lights_routine(struct repeating_timer *t) {  
    printf("Luz %s desligou\n", cores[led_index]);
    led_state(leds_routine[led_index], false);

    led_index = led_index >= 2 ? 0 : led_index + 1;
    
    printf("Luz %s ligou" 
           "(passaram-se 3 segundos)\n",
           cores[led_index]);
           
    led_state(leds_routine[led_index], true);

    return true;
}

int main() {
    int accumulated_time = 0;
    struct repeating_timer timer;
    
    stdio_init_all();
    
    led_init(LED_RED_PIN);
    led_init(LED_YELLOW_PIN);
    led_init(LED_GREEN_PIN);

    add_repeating_timer_ms(
        3000, 
        traffic_lights_routine, 
        NULL, 
        &timer
    );

    led_state(LED_RED_PIN, true);

    uint16_t time_acm = 0;

    while (true) {
        sleep_ms(1000);
        time_acm += 1000;
        
        if(time_acm != 3000)
            printf("passou 1 segundo\n");
        else
            time_acm = 0;
    }

    return 0;

}
