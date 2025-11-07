#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
    PORTB ^= (1 << PB5); // When interrupt occurs, toggle LED on PB5 (D13)
}
void setup(void)
{
    // Set PB5 (Arduino D13) as output
    DDRB |= (1 << PB5);
    
    // Configure PD2 as input
    DDRD &= ~(1 << PD2);
    
    // Enable pull-up if needed
    PORTD |= (1 << PD2);
    
    // Trigger on rising edge:
    // ISC01 = 1, ISC00 = 0 for falling edge
    EICRA |= (1 << ISC01); EICRA &= ~(1 << ISC00);
    
    // Clear any pending interrupt flag for INT0
    EIFR |= (1 << INTF0);
    // Enable external interrupt for INT0
    EIMSK |= (1 << INT0);
    // Enable global interrupts
    sei();
}
void loop ()
    {

    }