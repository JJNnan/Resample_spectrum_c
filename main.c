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
    //�������
    int filenum;
     char spec[400][20];//�����ļ�����MAX400��



    int Nu;//���벨����
    int Sensor_NUM;
    int FWHM;//�����˹ģ���FWHM




    //��������
    void result();


    //��������
    dir();//��ȡspectrum�µĹ����ļ����浽dir.txt��
    filenum=read(spec);//����read������dir.txt�иո�ȡ���Ĺ���������д��������,filenumΪ�ļ�����


    printf("��ѡ�񴫸�������:1(MERIS[����������])��2(Hyperion)��3(AVIRIS)��4(TM)��5(MODIS)");
    scanf("%d",&Sensor_NUM);
    if(Sensor_NUM==1)
    {
        printf("�����벨������Number��:");
        scanf("%d",&Nu);

        MERIS(Nu,filenum,spec);
        printf("Done!\n");
    }
    else if(Sensor_NUM==2)
    {
        printf("������FWHM:");
        scanf("%d",&FWHM);

        Hyperion(FWHM,filenum,spec);
        printf("Done!\n");
    }
    else if(Sensor_NUM==3)
    {
        printf("������FWHM:");
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


