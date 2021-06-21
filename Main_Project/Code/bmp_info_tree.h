/* Bmp File display to Frame-buffer example  
* ----------------------------------------  
* FILE : BmpToFb.h  
* ---------------------------------------- */
#ifndef _BMPINFO_  
#define _BMPINFO_   

#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <string.h> 
#include <sys/ioctl.h> 
#include <sys/types.h> 
#include <linux/fb.h>   

// display area size 
#define WIDTH 1024 
#define HEIGHT 600  
#define READ_FILE_NAME1 "tree.bmp" 
#define READ_FILE_NAME2 "tree_star.bmp"

// make type definition - windows type 
typedef unsigned short U16; 
typedef unsigned short WORD; 
typedef unsigned int DWORD; 
typedef unsigned int LONG; 
typedef unsigned char BYTE;   

// make type definition - bmp file header  
typedef struct tagBITMAPFILEHEADER{         
	WORD bfType;         
	DWORD bfSize;         
	WORD bfReserved1;         
	WORD bfReserved2;         
	DWORD bfOffBits; } __attribute((packed))BITMAPFILEHEADER;   

// make type definition - bmp image infomation header 
typedef struct tagBITMAPINFOHEADER{         
	DWORD biSize;         
	LONG biWidth;         
	LONG biHeight;         
	WORD    biplanes;         
	WORD    biBitCount;         
	DWORD   biCompression;         
	DWORD   biSizeImage;         
	LONG    biXPelsPerMeter;         
	LONG    biYPelsPerMeter;         
	DWORD   biClrUsed;         
	DWORD   biClrImportant; } __attribute((packed)) BITMAPINFOHEADER;   
/* other mathod : Group Attribute Packed Mathod 
// #pragma pack(1) 
// #pragma pack() */   
#endif
