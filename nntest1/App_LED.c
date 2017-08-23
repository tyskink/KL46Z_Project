#include <MKL46Z4.H>


void InitLED(void)
{SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;//This enables the clock to PORTD
PORTD->PCR[5] = PORT_PCR_MUX(1u);//This sets the Mux control of PTD5 to 001, or GPIO
PTD->PDDR |= (1u<<5);}

void BlinkLED3(void)
			
{//Create a loop variable
PTD->PTOR = (1u<<5);//Toggles PTD5 and the LED
for(int i=0;i < 300000; i++){};//Burn some time
}
