#include<stdio.h>

typedef enum { OFF, ON } light_state;	/* state 선언 */
typedef enum { cancel_OFF, cancel_ON } cancel_command;	/* cancel input 여부 선언 */
typedef enum { call_OFF, call_ON } call_command;	/* call input 여부 선언 */

light_state state;

/* input */
cancel_command Cncl;
call_command Call;

int L;	/* output */

int main() {
	switch (state)
	{
	case ON: /* state */
		if (Cncl == 1 && Call == 0) /* (Cncl==cancel_ON && Call==cancel_OFF)으로 표현 가능 */
		{
			state = OFF; /* 다음 state */
			L = 0;
			break;
		}
		else if (Cncl==0 || Call==1)
		{
			state = ON;
			L = 1;
			break;
		}

	case OFF:
		if (Call==1)
		{
			state = ON;
			L = 1;
			break;
		}
		else if (Call==0)
		{
			state = OFF;
			L = 0;
			break;
		}
	default:
		break;
	}
}