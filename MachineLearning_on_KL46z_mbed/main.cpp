
#include "mbed.h"
#include "SDFileSystem.h"


SDFileSystem sd(PTA16, PTA17, PTA15, PTB9, "sd"); // the pinout on the mbed Cool Components workshop board  MOSI, MISO, SCLK, SSEL
 
 
DigitalOut led_red(LED_RED);
DigitalOut led_green(LED_GREEN);
DigitalIn sw2(SW1);
DigitalIn sw3(SW3);
Serial pc(USBTX, USBRX);

int main() 
	{

    pc.baud(115200);
		
printf(" Hello World from FRDM-K64F board.\r\n");    
printf(" ---------- START -------------- \r\n");

FILE *fp_X = fopen("/sd/X.kldouble", "rb"); 
FILE *fp_theta1 = fopen("/sd/theta1.kldouble", "rb"); 
FILE *fp_theta2 = fopen("/sd/theta2.kldouble", "rb"); 	
		

			if(fp_X == NULL) 
				{printf("fp_X  : open file error. \r\n");}
			else
			{		if(fp_theta1 == NULL) 
					{printf("fp_theta1 : open file error. \r\n");}
				else
				{		
					if(fp_theta2 == NULL) 
					{printf("fp_theta2  : open file error. \r\n");}
				else
					{		
						//printf("all files opened \r\n");
					}
				}
			}
		
//printf("creat variables\r\n");
			
//fread(&Theta2[0],sizeof(double),260,fp_theta2);			

//printf("{A}: %d Processing Start \r\n",result);
			
			
			


printf("{Z}:  Processing end,");
//printf("the result is %d \r\n",result);
fclose(fp_X);
fclose(fp_theta1);
fclose(fp_theta2);

 printf(" ----------END--------------- \r\n ");
    
}


 
