/*
 * Display.cpp
 *
 * Created: 2014-12-04 9:35:58 PM
 *  Author: amate_000
 */ 
#include "Arduino.h"
#include "Display.h"

Display::Display(const unsigned int * anodesPinArray,const unsigned int * cathodesPinArray)
{
	memcpy(anodePinRegistry, anodesPinArray, 8*sizeof(int));
	memcpy(cathodePinRegistry,  cathodesPinArray, 4*sizeof(int));	

	const unsigned int anodePinRegistry[10] = {126, 48, 109, 121, 51, 91, 95, 112, 127, 123};
	const unsigned int masks[7] = {1, 2, 4, 8, 16, 32, 64};
}

void Display::show(int number)
{
	for (int i=0; i<4; i++)
	{
		int currentNumber = number%10;
		clearDigits();
		activateDigit(i);
		number = (number-currentNumber)/10;
	}

	
}

void Display::clearDigits()
{
	for (int i=0; i<8; i++){
		digitalWrite(anodePinRegistry[i], LOW);
		while (i<4)
		{
			digitalWrite(cathodePinRegistry[i], HIGH);
		}
	}
}

void Display::activateDigit(int digit)
{
	digitalWrite(cathodePinRegistry[digit], LOW);
}

void Display::showNumber(int number)
{
	
}