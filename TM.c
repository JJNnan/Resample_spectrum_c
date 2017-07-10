#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<math.h>
#include"path.h"

double cac();
void result_tm();




int TM(int filenum,char spec[400][20])
{


    //定义数组读取不同波段的响应函数
    double blue[1941];
    double green[1941];
    double red[1941];
    double NIR[1941];
    double SWIR_1[1941];
    double SWIR_2[1941];

    double b;
    double g;
    double r;
    double n;
    double s1;
    double s2;
    double NDVI;

    double TM_spec[1941][7];


    //打开TM_response.txt光谱响应函数文件

    int i,j;
    FILE *fp1;
    fp1=fopen("LS8_response.txt","r");
    if(fp1==NULL)
        return -1;
    for(i=0;i<1941;i++)
    {
        for(j=0;j<7;j++)
        {
            fscanf(fp1,"%lf",&TM_spec[i][j]);
            //if(TM_spec[i][j]>0)
           // printf("%lf",TM_spec[i][j]);

        }
        fscanf(fp1,"\n");
    }
    fclose(fp1);
    //将读取的响应函数赋值给各波段
    for(i=0;i<1941;i++)
    {
        blue[i]=TM_spec[i][1];
        green[i]=TM_spec[i][2];
        red[i]=TM_spec[i][3];
        NIR[i]=TM_spec[i][4];
        SWIR_1[i]=TM_spec[i][5];
        SWIR_2[i]=TM_spec[i][6];

    }

    for( i=0;i<filenum;i++)
   {
	   //int k;
	   double specfile[2200];
	   char dir_spec[20]=".\\spectrum\\";
	   char dirr[50];
	   //int wave;



	   strcpy(dirr,dir_spec);
	   strcat(dirr,spec[i]);
	   openspectrum(dirr,specfile);//打开指定光谱文件，并传出值到specfile数组

	   b=cac(blue,specfile);
	   g=cac(green,specfile);
	   r=cac(red,specfile);
	   n=cac(NIR,specfile);
	   s1=cac(SWIR_1,specfile);
	   s2=cac(SWIR_2,specfile);
	   NDVI=fabs((n-r)/(n+r));


	   result_tm(spec[i],b,g,r,n,s1,s2,NDVI);

   }


}

double cac(double response[1941],double specfile[2200])
{
    int i;
    double res;
    double sum;
	double temp;
    double sum1;
    for(i=0,temp=0,sum=0,sum1=0;i<1941;i++)
        {
            temp=response[i];
            sum=sum+temp;
            sum1=sum1+specfile[i+70]*temp;
        }
		   res=sum1/sum;
		   return res;

}
