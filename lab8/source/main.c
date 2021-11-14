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
	unsigned short max = 0xFF ;
	unsigned decrement = max / 8 ;
	while(1){
		x = ADC ;
		unsigned char i = (char) x ;
		if (i <= (decrement * 1)) PORTB = 0x01;
		else if (i <= (decrement * 2)) PORTB = 0x03;
		else if (i <= (decrement * 3)) PORTB = 0x07;
		else if (i <= (decrement * 4)) PORTB = 0x0F;
		else if (i <= (decrement * 5)) PORTB = 0x1F;
		else if (i <= (decrement * 6)) PORTB = 0x3F;
		else if (i <= (decrement * 7)) PORTB = 0x7F;
		else if (i <= (decrement * 8)) PORTB = 0xFF;
	}
    return 1;
}
