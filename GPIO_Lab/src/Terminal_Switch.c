#include "Terminal_Switch.h"

int Decision_Maker()
{
	LOOP:;
		uint8_t b;
 		printf("Please Input A Number 1 or 2\n\r");
		b = getc(stdin);
		if(b==0x31)
		{
			return b;
		}
		else if (b==0x32)
		{
			return b;
		}
		else 
		{
		printf("There's No Need To Be A Little Fuck.. Put In A 1 Or 2\n\r");
			goto LOOP;
		}
}