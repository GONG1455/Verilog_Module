#ifndef _BMP_IMG_H
#define _BMP_IMG_H
#include "xsdps.h"
#include "ff.h"
#endif
typedef unsigned short int WORD;
typedef unsigned int DWORD;
typedef int LONGG;
typedef unsigned char BYTE;

/*********** *********** *********** *********** *********** *********** ***********
* definition :struct
* Description :λͼ�ļ�ͷ
*********** *********** *********** *********** *********** *********** ***********/
#pragma pack(1)/////////////////���ṹ���г�Ա��n�ֽڶ���
typedef struct tagBITMAPFILEHEADER
{
    WORD bfType;////////////////�ļ����ͣ�����ΪBM
    DWORD bfSize;///////////////ָ���ļ���С�����ֽ�Ϊ��λ��3-6�ֽڣ���λ��ǰ��
    WORD bfReserved1;///////////�ļ������֣�����Ϊ0
    WORD bfReserved2;///////////�ļ������֣�����Ϊ0
    DWORD bfOffBits;////////////���ļ�ͷ��ʵ��λͼ���ݵ�ƫ���ֽ�����11-14�ֽڣ���λ��ǰ��
}BITMAPFILEHEADER;
/*********** *********** *********** *********** *********** *********** ***********
* definition :struct
* Description :λͼ��Ϣͷ
*********** *********** *********** *********** *********** *********** ***********/
typedef struct tagBITMAPINFOHEADER
{
	DWORD biSize;///////////////���ṹ��ռ���ֽ�����Ϊ40��ע�⣺ʵ�ʲ���������44�������ֽڲ����ԭ��
	LONGG biWidth;///////////////λͼ�Ŀ�ȣ�������Ϊ��λ
	LONGG biHeight;//////////////λͼ�ĸ߶ȣ�������Ϊ��λ
	WORD biPlanes;//////////////Ŀ���豸�ļ��𣬱���Ϊ1
	WORD biBitCount;////////////ÿ�����������λ����1��˫ɫ����4(16ɫ����8(256ɫ��16(�߲�ɫ)��24�����ɫ����32֮һ
	DWORD biCompression;////////λͼѹ�����ͣ�0����ѹ������1(BI_RLE8ѹ�����ͣ���2(BI_RLE4ѹ�����ͣ�֮һ
	DWORD biSizeImage;//////////λͼ�Ĵ�С(���а�����Ϊ�˲���������4�ı�������ӵĿ��ֽ�)�����ֽ�Ϊ��λ
	LONGG biXPelsPerMeter;///////λͼˮƽ�ֱ��ʣ�ÿ��������
	LONGG biYPelsPerMeter;///////λͼ��ֱ�ֱ��ʣ�ÿ��������
	DWORD biClrUsed;////////////λͼʵ��ʹ�õ���ɫ���е���ɫ��������ֵΪ0,��ʹ����ɫ��Ϊ2��biBitCount�η�
	DWORD biClrImportant;///////λͼ��ʾ��������Ҫ����ɫ��������ֵΪ0,�����е���ɫ����Ҫ
}BITMAPINFOHEADER;
#pragma pack()//////////////////ȡ���Զ����ֽڷ�ʽ
/*********** *********** *********** *********** *********** *********** ***********
* definition :struct
* Description :��ɫ��
*********** *********** *********** *********** *********** *********** ***********/
typedef struct tagRGBQUAD
{
	BYTE rgbBlue;///////////////��ɫ�����ȣ�0-255)
	BYTE rgbGreen;//////////////��ɫ�����ȣ�0-255)
	BYTE rgbRed;////////////////��ɫ�����ȣ�0-255)
	BYTE rgbReserved;///////////����������Ϊ0
}RGBQUAD;

/*********** *********** *********** *********** *********** *********** ***********
* Function Name :printInfo
* Description :����ļ���Ϣ
*********** *********** *********** *********** *********** *********** ***********/
void printInfo(BITMAPFILEHEADER fileHeader,BITMAPINFOHEADER infoHeader);
/*********** *********** *********** *********** *********** *********** ***********
* Function Name :printInfo
* Description :���������Ϣ
*********** *********** *********** *********** *********** *********** ***********/
void printPalette(RGBQUAD *rgbPalette,int sizeOfPalette);
//int ReadBmp(BITMAPFILEHEADER fileHeader,BITMAPINFOHEADER infoHeader,RGBQUAD *rgbPalette/*����ȥ����һ��仯*/,void *img[5000],char *FileName);
int SaveBmp(BITMAPFILEHEADER fileHeader,BITMAPINFOHEADER infoHeader,RGBQUAD *rgbPalette,u8 *img,char *FileName);
