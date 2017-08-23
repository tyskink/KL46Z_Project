#include "mbed.h"
#include "SDFileSystem.h"
 

SDFileSystem sd(PTA16, PTA17, PTA15, PTB9, "sd"); // the pinout on the mbed Cool Components workshop board  MOSI, MISO, SCLK, SSEL
 
 
DigitalOut led_red(LED_RED);
DigitalOut led_green(LED_GREEN);
DigitalIn sw2(SW1);
DigitalIn sw3(SW3);
Serial pc(USBTX, USBRX);
 
char charbuffer[25]; 
float floatbuffer[5]={2.34,5.67,23.45,56.89,135.577};
float floatbufferempty[10];

double doublebufferempty[401];
int main() {
   
    led_green = 1;
    led_red = 1;
    pc.baud(115200);
    pc.printf("pc.printf: Hello World from FRDM-K64F board.\r\n");    
    //printf("printf: Hello World!\r\n");   t1.kldouble
    
 printf(" ---------- START -------------- \r\n ");

			FILE *fp2 = fopen("/sd/theta1.kldouble", "rb"); 
			if(fp2 == NULL) 
				{printf("fp2: open file error. \r\n");}
			else
			{
				
					fread(&doublebufferempty[0],sizeof(double),401,fp2);
				
					for(int i=0;i<401;i++)
					{
					printf("%f\r\n",doublebufferempty[i]);
					}
				
			}
			

	
 printf(" ----------END--------------- \r\n ");
    
}


/* example: write and read binary directly: good
		FILE *fp1 = fopen("/sd/testfloat1.txt", "w"); 
			if(fp1 == NULL) 
				{printf("fp1: open file error. \r\n");}
			else
			{
				fwrite(&floatbuffer[0],sizeof(float),5,fp1);
			}
		fclose(fp1);	
			
			FILE *fp2 = fopen("/sd/testfloat1.txt", "rb+"); 
			if(fp2 == NULL) 
				{printf("fp2: open file error. \r\n");}
			else
			{
				fread(&floatbufferempty[0],sizeof(float),5,fp2);
			}
			
			for(int i=0;i<5;i++)
			{
			printf("%f\r\n",floatbufferempty[i]);
			}
*/



/* file system: read example: good
		FILE *fp1 = fopen("/sd/test1.txt", "rb+"); 
			if(fp1 == NULL) 
				{printf("fp1: open file error. \r\n");}
			else
			{
				fread(&charbuffer[0],sizeof(char),11,fp1);
			}
			
			printf("%s\r\n",charbuffer);

*/




/*  file examples 
    FILE *fp = fopen("/sd/test1.txt", "w");                 // open file, if not exit, create one
    if(fp == NULL) 
    {
        printf("fp1: Could not open file for write. \r\n");
			
    }
    else
    {			
            //fprintf(fp, "1: Hello fun SD Card World!\r\n");   // write text to the file			
            fclose(fp); 
    }
 
 
    
    mkdir("/sd/mydir", 0777);
    
    FILE *fp2 = fopen("/sd/test2.txt", "w");
    if(fp2 == NULL) 
    {
        printf("fp2: Could not open file for write. \r\n");
    }
        else
    {
            fprintf(fp2, "fp2: Hello fun SD Card World!\r\n");
            fclose(fp2); 
    }
    

*/


/*
						  char buff[16] = {0};
							while (!feof(fp))
							{
								int size = fread(&buff[0], 1, 15, fp);
								fwrite(&buff[0], 1, size. 
							}
			
*/	
			

 /** Example:
 * @code
 * #include "mbed.h"
 *
 * LocalFileSystem local("local");               // Create the local filesystem under the name "local"
 *
 * int main() {
 *     FILE *fp = fopen("/local/out.txt", "w");  // Open "out.txt" on the local file system for writing
 *     fprintf(fp, "Hello World!");
 *     fclose(fp);
 *     remove("/local/out.txt");                 // Removes the file "out.txt" from the local file system
 *
 *     DIR *d = opendir("/local");               // Opens the root directory of the local file system
 *     struct dirent *p;
 *     while((p = readdir(d)) != NULL) {         // Print the names of the files in the local file system
 *       printf("%s\n", p->d_name);              // to stdout.
 *     }
 *     closedir(d);
 * }
 * @endcode
 * */
 