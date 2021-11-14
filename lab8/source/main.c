/*	Author: sspon001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 8  Exercise 1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short x = 0x00 ;
void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE) ;
}

int main(void) {
	DDRA = 0x00 ; PORTA = 0xFF ;
	DDRB = 0xFF ; PORTB = 0x00 ;
	DDRC = 0xFF ; PORTC = 0x00 ;
	DDRD = 0xFF ; PORTD = 0x00 ;
	ADC_init() ;
	unsigned short max = 0x8A ;
	unsigned short min = 0x30 ;
    while (1) {
	    x = ADC ;
	    PORTB = 0x00 ;
	    if(x >= (max/2)) PORTB = 0x01 ;
	    else PORTB = 0x00 ;
    }
    return 1;
}
