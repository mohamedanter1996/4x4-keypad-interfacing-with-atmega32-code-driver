/*
 * keypad.c
 *
 * Created: 15/12/2019 11:43:35 ص
 *  Author: mohamed anter
 */ 
#include <avr/io.h>
#include <Amit/IOmohameddriver.h>
#include <util/delay.h>
#include <Amit/LCD_4bits.h>
#include "keypad.h"

int keypadRow[] = {R0, R1, R2, R3}; //rows of the keypad
int keypadCol[] = {C0, C1, C2, C3};//columnd
int Keycounter=0;
int fristtimeflage=0;

int Key_cursorposition()
{
	if ((Keycounter==1)&&(fristtimeflage==0))
	{
		Keycounter=0;
		fristtimeflage=1;
	}
	return Keycounter;
}

keyinit()
{
	keypadDDR |= (1<<R0)|(1<<R1)|(1<<R2)|(1<<R3);//set upper part of keypad port as output
	//this will be required for scanning the rows
	keypadDDR &= ~((1<<C0)|(1<<C1)|(1<<C2)|(1<<C3));//set lower part of keypad port as input.This is
	//the part of the keypad port where the rows are connected.

}

char getkey()
{
	
	int i, j;
	for(i = 0; i < 4; i++)
	{
		keypadPORT = 0x00;
		
		keypadPORT |= (1 << keypadRow[i]);//send a high to a particular row of the keypad

		for(j = 0; j < 4; j++)
		{
			if((readPin(keypadCol[j],D)==1))//check if key is pressed
			{
				while((readPin(keypadCol[j],D)));  //wait for key to be released
				switch(i)
				{
					case(0):
					{
						if (j == 0)
						{
							Keycounter++;
							return '1';
						}
						else if (j == 1)
						{
							Keycounter++;
							return '2';
						}
						
						else if (j == 2)
						{
							Keycounter++;
							return '3';
						}
						else if (j == 3)
						{
							Keycounter++;
							return 'A';
						}
						
						break;
					}
					case(1):
					{
						if (j == 0)
						{
							Keycounter++;
							return '4';
						}
						else if (j == 1)
						{
							Keycounter++;
							return '5';
						}
						
						else if (j == 2)
						{
							Keycounter++;
							return '6';
						}
						else if (j == 3)
						{
							Keycounter++;
							return 'B';
						}
						break;
					}
					case(2):
					{
						if (j == 0)
						{
							Keycounter++;
							return '7';
						}
						else if (j == 1)
						{
							Keycounter++;
							return '8';
						}
						
						else if (j == 2)
						{
							Keycounter++;
							return '9';
						}
						else if (j == 3)
						{
							Keycounter++;
							return 'C';
						}
						break;
					}
					case(3):
					{
						if (j == 0)
						{
							Keycounter++;
							return '*';
						}
						else if (j == 1)
						{
							Keycounter++;
							return '0';
						}
						
						else if (j == 2)
						{
							Keycounter++;
							return '#';
						}
						else if (j == 3)
						{
							Keycounter++;
							return 'D';
						}
						break;
					}
				}
			}
			
			
		}
	}
	
}