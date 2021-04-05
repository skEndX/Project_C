#include <stdio.h>

void stateA(void);
void stateB(void);
void stateC(void);
void initializeSM(void);
void wait(void);
/* state�� ���� ���� */
typedef enum { STATE_A = 0, STATE_B, STATE_C } State_Type;
/* ������ �迭�� ����� state�� �̵�*/
static void(*state_table[])(void) = { stateA, stateB, stateC };

static State_Type curr_state; /* state */
static int Clock;
static int out;

void main(void)
{
	initializeSM();	//�ʱ� ����

	while (1) {
		state_table[curr_state]();	//state ����
		wait();
		Clock++;
	}
}

void stateA(void)	//���� state
{
	if (Clock == 2) {
		curr_state = STATE_B; /* ���� State */
		out = 1; 
	}
}
void stateB(void)
{
	if (Clock == 5) { 
		curr_state = STATE_C;
		out = 2; 
	}
}
void stateC(void)
{
	if (Clock == 9) { 
		Clock = 0;
		curr_state = STATE_A; 
		out = 0; 
	}
}

void initializeSM(void)
{
	curr_state = STATE_A;
	out = 0;
	Clock = 1;
}
