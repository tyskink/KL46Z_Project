
#include "mbed.h"
#include "DL_Math.h"
#include "SDFileSystem.h"


SDFileSystem sd(PTA16, PTA17, PTA15, PTB9, "sd"); // the pinout on the mbed Cool Components workshop board  MOSI, MISO, SCLK, SSEL
 
 
DigitalOut led_red(LED_RED);
DigitalOut led_green(LED_GREEN);
DigitalIn sw2(SW1);
DigitalIn sw3(SW3);
Serial pc(USBTX, USBRX);
 

 
 
int layer1(FILE *fp_X,FILE *fp_theta,double* output)
{
double Xbuffer[401];
double thetabuffer[401];

Xbuffer[0]	=1;
	
fread(&Xbuffer[1],sizeof(double),400,fp_X);
//printf("load the X value finished. \r\n");
	
	
for (int theta1_rows=0;theta1_rows<25;theta1_rows++)
{	
	
	fread(&thetabuffer[0],sizeof(double),401,fp_theta);
	//printf(" load the theta value finished \r\n");
	vector_multpile( &Xbuffer[0], &thetabuffer[0], 401, output+theta1_rows);
	
	//printf(" the %d rows is %f \r\n",theta1_rows, *(output+theta1_rows));
}	
		return 0;
}

int layer2(double *h1,FILE *fp_theta2,double* output)
{
	double Theta2[10][26] = { 0 };
	
	fread(&Theta2[0],sizeof(double),260,fp_theta2);
	
	matrix_multpile(&Theta2[0][0],10, 26, &h1[0], 26, 1, &output[0]);
	return 0;
}

int main() 
	{
    led_green = 1;
    led_red = 1;
    pc.baud(115200);
double h1[26]={0};
double h2[10] = { 0 };
h1[0] = 1;
int result=0;


double Theta2[10][26] = { 0 };
		
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
			
fread(&Theta2[0],sizeof(double),260,fp_theta2);			

printf("{A}: %d Processing Start \r\n",result);
			
			
			

for(int i=0;i<5000;i++)
{
	rewind(fp_theta1);
	//rewind(fp_theta2);
		
	layer1(fp_X,fp_theta1,&h1[1]);	
	sigmoidMatrix(&h1[0], 26);
		
	//layer2(&h1[0],fp_theta2,&h2[0]);
		matrix_multpile(&Theta2[0][0],10, 26, &h1[0], 26, 1, &h2[0]);
	sigmoidMatrix(&h2[0], 10);
		
	result+=maxofMatrix(&h2[0], 10);
	
//printf("the result is %d \r\n",result);
}

printf("{Z}:  Processing end,");
printf("the result is %d \r\n",result);
fclose(fp_X);
fclose(fp_theta1);
fclose(fp_theta2);

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
 
