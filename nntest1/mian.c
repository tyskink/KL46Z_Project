#include <MKL46Z4.H>

#include "pin_mux.h"
#include "clock_config.h"

#include "USB_CDC.h"

#include "ML_Models.h"



		
int main(void)
	{
	

		
		BOARD_InitPins();
    BOARD_BootClockRUN();
		
		USBInit();
		

		while(1)
		{
		 USB_CDC_task();
			
			//NN_2Lyaers_1();
		}
		return 0;
		
	}

