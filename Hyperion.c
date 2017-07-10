#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<math.h>
#include"path.h"
int Hyperion(int FWHM,int filenum,char spec[400][20])
{
    int i,j;
    for(i=0;i<filenum;i++)
   {
	   int k;
	   double specfile[2200];

	   char dir_spec[20]=".\\spectrum\\";
	   char dirr[50];

	   double row;
	   int wave;

	   double sum=0;
	   double temp=0;
	   double sum1=0,B1;

	   strcpy(dirr,dir_spec);
	   strcat(dirr,spec[i]);
	   openspectrum(dirr,specfile);//打开指定光谱文件，并传出值到specfile数组


       row=FWHM/(2*sqrt(2*log(2)));





	   for(j=0;j<215;j++)
        {

            for(temp=0,sum=0,sum1=0,k=0;k<FWHM+1;k++)
            {
                temp=exp(-(k-FWHM/2)*(k-FWHM/2)/(2*row*row));
                sum=sum+temp;
                sum1=sum1+specfile[k+j*10]*temp;

		   }
		   wave=355+j*10;
		   B1=sum1/sum;

		    result(spec[i],wave,B1);


	   }


   }


}
