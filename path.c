#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

char spec[400][20];//光谱文件名（MAX400）
//读取dir.txt函数
int read(char v[100][20])
{

	int i=0;
	FILE *fp;
	fp= fopen("dir.txt","r");
	if(fp==NULL)
		return -1;
	while(fscanf(fp ,"%s",v[i]) !=EOF)
		i++;
	fclose(fp);
	return i;
}

//取出指定文件夹下所有txt文件名
void dir()
{
	system("dir /b .\\spectrum\\*.txt >>.\\dir.txt");
	//printf("done!\n");
}
//打开光谱文件函数，dirr为含文件路径文件
int openspectrum(char dirr[50],double specfile[2200])
{
	double v[2200][2];
	int i=0,j;
	FILE *fp;
	fp= fopen(dirr,"r");
	if(fp==NULL)
		return -1;
	for(i=0;i<2200;i++)
	{
		for(j=0;j<2;j++)
		{
			fscanf(fp,"%lf",&v[i][j]);
		}

		fscanf(fp,"\n");
	}
	fclose(fp);

	for(i=0;i<2200;i++)
	{

			specfile[i]=v[i][1];
	}
	return 0;
}

//结果写入对应的txt中
void result(char spec[20],int wave,double B1)
{
    char a[20]=".\\result\\";
    char adirr[50];
    strcpy(adirr,a);
    strcat(adirr,spec);
	FILE *fp=fopen(adirr,"a");
	fprintf(fp,"%d",wave);
	fprintf(fp,"\t");
	fprintf(fp,"%.6lf",B1);
	fprintf(fp,"\n");
	fclose(fp);
}

//TM输出函数
void result_tm(char spec[20],double BLUE,double GREEN,double RED,double NIR,double SWIR_1,double SWIR_2,double NDVI)
{
    char a[20]=".\\result\\";
    char adirr[50];
    strcpy(adirr,a);
    strcat(adirr,spec);
	FILE *fp=fopen(adirr,"a");

	fprintf(fp,"Blue");
	fprintf(fp,"\t");
	fprintf(fp,"483");
	fprintf(fp,"\t");
	fprintf(fp,"%.6lf",BLUE);
	fprintf(fp,"\n");

    fprintf(fp,"Green");
	fprintf(fp,"\t");
	fprintf(fp,"560");
	fprintf(fp,"\t");
	fprintf(fp,"%.6lf",GREEN);
	fprintf(fp,"\n");

	fprintf(fp,"Red");
	fprintf(fp,"\t");
	fprintf(fp,"662");
	fprintf(fp,"\t");
	fprintf(fp,"%.6lf",RED);
	fprintf(fp,"\n");

	fprintf(fp,"NIR");
	fprintf(fp,"\t");
	fprintf(fp,"835");
	fprintf(fp,"\t");
	fprintf(fp,"%.6lf",NIR);
	fprintf(fp,"\n");

	fprintf(fp,"SWIR_1");
	fprintf(fp,"\t");
	fprintf(fp,"1648");
	fprintf(fp,"\t");
	fprintf(fp,"%.6lf",SWIR_1);
	fprintf(fp,"\n");

	fprintf(fp,"SWIR_2");
	fprintf(fp,"\t");
	fprintf(fp,"2206");
	fprintf(fp,"\t");
	fprintf(fp,"%.6lf",SWIR_2);
	fprintf(fp,"\n");

	fprintf(fp,"NDVI");
	fprintf(fp,"\t");
	fprintf(fp,"NDVI");
	fprintf(fp,"\t");
	fprintf(fp,"%.6lf",NDVI);
	fprintf(fp,"\n");
	fclose(fp);
}

//modis输出
void result_MODIS(char spec[20],double result_modis[20])
{
    int i;
    double wavelength[20]={0.4125,0.443,0.469,0.488,0.531,0.551,0.555,0.615,0.645,0.667,0.678,0.748,0.8585,0.8695,0.905,0.936,0.94,1.375,1.64,2.13};
    char a[20]=".\\result\\";
    char adirr[50];
    strcpy(adirr,a);
    strcat(adirr,spec);
	FILE *fp=fopen(adirr,"a");

	for(i=0;i<20;i++)
    {
        fprintf(fp,"%.6lf",wavelength[i]);
        fprintf(fp,"\t");
        fprintf(fp,"%.6lf",result_modis[i]);
        fprintf(fp,"\n");
    }




	fclose(fp);
	return 0;
}
