#include <stdio.h>
#include<conio.h>

void stateA(void);
void stateB(void);
void stateC(void);
void stateD(void);
void initializeSM(void);
//void wait(void);

typedef enum { STATE_A = 0, STATE_B, STATE_C, STATE_D } State_Type;

static void(*state_table[])(void) = { stateA, stateB, stateC,stateD };

static State_Type curr_state;
static int Clock;
static int out;
static int b = 0;

void main(void)
{

	initializeSM();

	while (1) {
		b = getch();
		state_table[curr_state]();
		//wait();
		Clock++;
		if (b=='0')
		{
			break;
		}
	}
}
void stateA(void)
{
	if (Clock == 2) { //change state 조건
		curr_state = STATE_B;	//다음 state
		out = 1;
		printf("STATE_B   out = %d	Clock = %d\n", out, Clock);
	}
}
void stateB(void)
{
	if (Clock == 5) { 
		curr_state = STATE_C;
		out = 2; 
		printf("STATE_C   out = %d	Clock = %d\n", out, Clock);
	}
}
void stateC(void)
{
	if (Clock == 9) {
		curr_state = STATE_D; 
		out = 3; 
		printf("STATE_D   out = %d	Clock = %d\n", out, Clock);
	}
}
void stateD(void)
{
	if (Clock == 14) {
		curr_state = STATE_A;
		out = 0;
		printf("STATE_A   out = %d	Clock = %d\n", out, Clock);
		Clock = 0;
	}
}
void initializeSM(void)
{
	curr_state = STATE_A;
	out = 0;
	Clock = 1;
	printf("STATE_A   out = %d	Clock = %d\n", out, Clock);
}