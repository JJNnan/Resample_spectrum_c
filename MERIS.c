#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<math.h>
#include"path.h"




//打开FWHM(中心波长、FWHM)
int FWHM_file(double mid_wavelength[],double FWHM[],int Number)
{
	FILE *fp;
	double a[Number][2];
	int i,j;
	fp=fopen("Meris_FWHM.txt","r");
		if(fp==NULL)
		return -1;
	for(i=0;i<Number;i++)
	{
		for(j=0;j<2;j++)
		{
			fscanf(fp,"%lf",&a[i][j]);
		}
			fscanf(fp,"\n");
	}
	fclose(fp);
	for(i=0;i<Number;i++)
	{
			mid_wavelength[i]=a[i][0];
			FWHM[i]=a[i][1];
	}
	return 0;
}

int MERIS(int Nu,int filenum,char spec[400][20])
{
    int i,j;
    for(i=0;i<filenum;i++)
   {
	   int k;
	   double specfile[2200];

	   char dir_spec[20]=".\\spectrum\\";
	   char dirr[50];

	   double mid_wavelength[Nu];
	   double FWHM[Nu];

	   int F;
	   double row;
	   int wave;

	   double sum=0;
	   double temp=0;
	   double sum1=0,B1;

	   strcpy(dirr,dir_spec);
	   strcat(dirr,spec[i]);
	   openspectrum(dirr,specfile);//打开指定光谱文件，并传出值到specfile数组
	   FWHM_file(mid_wavelength,FWHM,Nu);

	   for(j=0;j<Nu;j++)
        {
            F=FWHM[j];
            wave=mid_wavelength[j];
            row=F/(2*sqrt(2*log(2)));
            for(temp=0,sum=0,sum1=0,k=0;k<F+1;k++)
            {
                temp=exp(-(k-F/2)*(k-F/2)/(2*row*row));
                sum=sum+temp;
                sum1=sum1+specfile[wave-F/2-350+k]*temp;

		   }

		   B1=sum1/sum;

		    result(spec[i],wave,B1);


	   }


   }
   return 0;

}
