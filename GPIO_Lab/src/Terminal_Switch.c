#include "Terminal_Switch.h"

int Decision_Maker()
{
	LOOP:;
		uint8_t b;
 		printf("Please Input A Number 1 or 2\n\r"); // you get more bees with honey than vinegar
		b = getc(stdin);
		if(b==0x31)																	// comparing value to 1
		{
			return b;
		}
		else if (b==0x32)														// comparing value to 2	
		{
			return b;
		}
		else 																				// Rules are made for a reason
		{
		printf("There's No Need To Be A Little Fuck.. Put In A 1 Or 2\n\r");		// Keep em on their toes..
			goto LOOP;
		}
}