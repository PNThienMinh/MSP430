#include <msp430.h>				


/**
 * blink.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
	P1DIR |= BIT0+BIT6;;// configure P1.0 as output
	P1OUT |= BIT0;
	P1OUT &= ~BIT6;

	P1DIR &= ~BIT3;
	P1REN |= BIT3;
	P1OUT |= BIT3;




	volatile unsigned int i=0;		// volatile to prevent optimization

	while(1)
	{
	        if((P1IN & BIT3)!=BIT3)
	       {
	            while((P1IN & BIT3)!= BIT3){__delay_cycles(10000);}
	            i++;
	            if(i==6)
	            {
	                P1OUT ^= BIT0 +BIT6 ;
	                i=0;
	            }

	       }
	       				// toggle P1.0

	}
}
