#include <avr/io.h> // for input/output registers

int main()
{
    unsigned char inp; // for taking in input

    DDRA = 0x00; // input port
    DDRB = 0xFF; // output port
    PORTA = 0xFF; // (Pull-up)

    while (1) { // Infinite loop
        inp = PINA;

        if (inp == 0b11111111) // Left Sensor = 1 and Right Sensor = 1
            PORTB = 0b00001010; // Both motors Forward
        if (inp == 0b11111101) // At Left Sensor = 0 and Right Sensor = 1
            PORTB = 0b00000010; // Stop Left motor and move Right motor Forward
        if (inp == 0b11111110) // At Left Sensor = 1 and Right Sensor = 0
            PORTB = 0b00001000; // Stop Right motor and move Left motor Forward
    }
    return 0;
}
