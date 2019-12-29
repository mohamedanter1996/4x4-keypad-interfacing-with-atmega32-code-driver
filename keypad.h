/*
 * keypad.h
 *
 * Created: 15/12/2019 11:41:47 ص
 *  Author: mohamed anter
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define R0 7
#define R1 6
#define R2 5
#define R3 4
#define C0 3
#define C1 2
#define C2 1
#define C3 0

#define keypadPORT PORTD
#define keypadPIN PIND
#define keypadDDR DDRD

void keyinit(void);

char getkey(void);

int Key_cursorposition(void);



#endif /* KEYPAD_H_ */