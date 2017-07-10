#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include<math.h>
#include"MERIS.h"
#include"path.h"
#include"TM.h"
#include"Hyperion.h"
#include"AVIRIS.h"
#include"MERIS.h"
#include"MODIS.h"

int main()
{
    //定义参数
    int filenum;
     char spec[400][20];//光谱文件名（MAX400）



    int Nu;//输入波段数
    int Sensor_NUM;
    int FWHM;//输入高斯模拟的FWHM




    //声明函数
    void result();


    //函数调用
    dir();//读取spectrum下的光谱文件保存到dir.txt中
    filenum=read(spec);//调用read函数将dir.txt中刚刚取出的光谱数据名写入数组中,filenum为文件个数


    printf("请选择传感器类型:1(MERIS[其他传感器])、2(Hyperion)、3(AVIRIS)、4(TM)、5(MODIS)");
    scanf("%d",&Sensor_NUM);
    if(Sensor_NUM==1)
    {
        printf("请输入波段数（Number）:");
        scanf("%d",&Nu);

        MERIS(Nu,filenum,spec);
        printf("Done!\n");
    }
    else if(Sensor_NUM==2)
    {
        printf("请输入FWHM:");
        scanf("%d",&FWHM);

        Hyperion(FWHM,filenum,spec);
        printf("Done!\n");
    }
    else if(Sensor_NUM==3)
    {
        printf("请输入FWHM:");
        scanf("%d",&FWHM);

        AVIRIS(FWHM,filenum,spec);
        printf("Done!\n");
    }
    else if(Sensor_NUM==4)
    {

        TM(filenum,spec);
        printf("Done!\n");

    }
    else if(Sensor_NUM==5)
    {
        MODIS(filenum,spec);
        printf("Done!\n");
    }
    remove("dir.txt");



    return 0;
}


