#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<math.h>
#include"path.h"

double cac_MODIS();
void result_MODIS();




int MODIS(int filenum,char spec[400][20])
{


    //定义数组读取不同波段的响应函数



    double MODIS_response[615][21];


    //打开TM_response.txt光谱响应函数文件

    int i,j;
    FILE *fp1;
    fp1=fopen("MODIS_response.txt","r");
    if(fp1==NULL)
        return -1;
    for(i=0;i<615;i++)
    {
        for(j=0;j<21;j++)
        {
            fscanf(fp1,"%lf",&MODIS_response[i][j]);
            //if(TM_spec[i][j]>0)
          // printf("%lf",MODIS_response[i][j]);

        }
        fscanf(fp1,"\n");
    }
    fclose(fp1);

    for( i=0;i<filenum;i++)
   {
	   int k,m,n,l;
	   double specfile[2200];
	   double spec_modis[620];
	   double result_modis[20];


	   char dir_spec[20]=".\\spectrum\\";
	   char dirr[50];
	   //int wave;
	   strcpy(dirr,dir_spec);
	   strcat(dirr,spec[i]);
	   openspectrum(dirr,specfile);//打开指定光谱文件，并传出值到specfile数组

	   for(k=0,m=0;k<617;k=k+6)
       {
           spec_modis[k]=specfile[m];
           //printf("%lf",spec_modis[k]);
           m=m+4;
           spec_modis[k+1]=specfile[m];
           m=m+3;
           spec_modis[k+2]=specfile[m];
           m=m+4;
           spec_modis[k+3]=specfile[m];
           m=m+3;
           spec_modis[k+4]=specfile[m];
           m=m+4;
           spec_modis[k+5]=specfile[m];
           m=m+3;

       }


       for(n=1;n<21;n++)
       {
           double modis_1[615];
           for(l=0;l<615;l++)
            {
                modis_1[l]=MODIS_response[l][n];
            }

           result_modis[n-1]=cac_MODIS(modis_1,spec_modis);
           //printf("%lf",result_modis[n-1]);
       }




	   result_MODIS(spec[i],result_modis);

   }
   return 0;


}

double cac_MODIS(double response[615],double specfile[620])
{
    int i;
    double res;
    double sum;
	double temp;
    double sum1;
    for(i=0,temp=0,sum=0,sum1=0;i<615;i++)
        {
            temp=response[i];
            sum=sum+temp;
            sum1=sum1+specfile[i]*temp;
        }
		   res=sum1/sum;
		   return res;

}

