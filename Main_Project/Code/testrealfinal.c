#include <stdio.h>
#include "bmp_info_tree.h"   
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/fb.h>
#include "touch.h"
#include <sys/stat.h>
#include <signal.h>
#define MAX_BUTTON 9
#define DEPTH 3 /* 24 Bit */ 

typedef unsigned int U32; 
unsigned int makepixel(U32  r, U32 g, U32 b)
{
    return (U32)((r<<16)|(g<<8)|b);
}

unsigned int m_touch_pos[14];

int fbrect(int a, int b,int c,int d)
{
    int check;
    int frame_fd;
    U32 pixel;
    int offset;
    int posx1, posy1, posx2, posy2;
    int repx, repy;
    struct fb_var_screeninfo fvs;
 
    if((frame_fd = open("/dev/fb0",O_RDWR))<0) {
        perror("Frame Buffer Open Error!");
        exit(1);
    }
 
    if((check=ioctl(frame_fd,FBIOGET_VSCREENINFO,&fvs))<0) {
        perror("Get Information Error - VSCREENINFO!");
        exit(1);
    }
 
    if(fvs.bits_per_pixel != 32) {
        perror("Unsupport Mode. 32Bpp Only.");
        exit(1);
    }
 
    if(lseek(frame_fd, 0, SEEK_SET) < 0) {  // Set Pixel Map
        perror("LSeek Error.");
        exit(1);
    }
 
    pixel = makepixel(a,b,c); // 색상 만들기
     unsigned int data[1024];
    unsigned char temp;
    /* multi-touch data process struct */
    typedef struct  touch_process_data__t   {
        unsigned    char    finger_cnt;
        unsigned    int     x1;
        unsigned    int     y1;
        unsigned    int     x2;
        unsigned    int     y2;
    } 
    touch_process_data_t;
    touch_process_data_t   ts_data;

    int count=0;
    int ret = 0;
    int press=0;
    int isMulti=0;
    int start_flag=1;
    int fingerCnt=1;
    int j;
    int cor_num;
    int fd;
    int i=0;
    memset(data,0,sizeof(data));
     fd=open("/dev/input/event2",O_RDWR);
    if(fd<0) {
        printf("Error!\n");
        return -1;
    }
	
    for(i=0;i<14;i++)
        m_touch_pos[i]=0;
    
        if(start_flag)
        {
            for(j=0;j<5;j++) //1 x y 0 0
            {
                ret=read(fd,&ts_data,sizeof(ts_data));
                if(ret!=-1) {
                    printf("%d ",ts_data.x2);
                    m_touch_pos[j]=ts_data.x2;
                }
            }
            start_flag=0;
        }
        else
        {
            cor_num=1;
            for(j=0;j<4;j++) //x y 0 0
            {
                ret=read(fd,&ts_data,sizeof(ts_data));
                if(ret!=-1) {
                    m_touch_pos[j]=ts_data.x2;
                }
            }
        }

        if(m_touch_pos[4-cor_num] > 1)
        {
            fingerCnt=2;
            for(j=0;j<3;j++)
            {
                ret=read(fd,&ts_data,sizeof(ts_data));
                if(ret!=-1)
                    m_touch_pos[j+5-cor_num]=ts_data.x2;
            }
        }
        else if(m_touch_pos[4-cor_num]==1)
            fingerCnt=0;
        else
        {
            fingerCnt=1;
//            printf("single= ");
        }

        if(m_touch_pos[7-cor_num] != 0 )
        {
            fingerCnt=3;
//            printf("triple= ");
            for(j=0;j<3;j++)
            {
                ret=read(fd,&ts_data,sizeof(ts_data));
                if(ret!=-1)
                    m_touch_pos[j+8-cor_num]=ts_data.x2;
            }
        }

        if(m_touch_pos[10-cor_num] != 0)
        {
            fingerCnt=4;
//            printf("quadra= ");
            for(j=0;j<3;j++)
            {
                ret=read(fd,&ts_data,sizeof(ts_data));
                if(ret!=-1)
                    m_touch_pos[j+11-cor_num]=ts_data.x2;
            }
        }
        
int k;
    for(k=0;k<4;k++)
            printf("%d ",m_touch_pos[k]);
        printf("\n");
        fingerCnt=0;

    posx1 = m_touch_pos[0]-d;  // 사각형의 크기를 결정한다.
    posx2 = m_touch_pos[0]+d;  
    posy1 = m_touch_pos[1]-d;
    posy2 = m_touch_pos[1]+d;
    
    for(repy=posy1; repy < posy2; repy++) {
        offset = repy * fvs.xres * (32/8) + posx1 * (32/8);
        if(lseek(frame_fd, offset, SEEK_SET) < 0) {
            perror("LSeek Error!");
            //exit(1);
        }
        for(repx = posx1; repx <= posx2; repx++)
            write(frame_fd, &pixel,(32/8));
    }
	
   
    close(fd);

   

    close(frame_fd);
    return 0;
}
 
void treestar_bmp() 
{         
	BITMAPFILEHEADER BmpFileHd;
	BITMAPINFOHEADER BmpInfoHd;

	unsigned char ImageBuffer[WIDTH*HEIGHT*DEPTH];         
	unsigned char Temp,r,g,b;         
	int i,h,w;         
	size_t retval;           
	int check;         
	int fb_fd;         
	U32 pixel;         
	int offset;         
	int posx1, posy1, posx2, posy2;         
	int repx, repy;         
	int pixcnt=0;         
	struct fb_var_screeninfo fvs;           

	FILE *fp=NULL;                    

	// File Open         
	if ((fp = fopen(READ_FILE_NAME2,"rb")) == NULL) {
		printf("File Open Error2\n");                 
		exit(1);         
	}           

	// File Read - read File Header         
	fread(&BmpFileHd, sizeof(BITMAPFILEHEADER), 1, fp);         
	if(BmpFileHd.bfType!=0x4D42) {                 
		printf("Not Bitmap file or Unsupport Bitmap file\n");                 
		exit(1);         
	}           

	printf("* BMP File Header - \n");        
	printf("  Type    : 0x%04X\n", BmpFileHd.bfType);         
	printf("  Size    : %d\n", BmpFileHd.bfSize);         
	printf("  Offbits : %d\n", BmpFileHd.bfOffBits);           

	// File Read          
	fread(&BmpInfoHd, sizeof(BITMAPINFOHEADER), 1, fp);         
	printf("* BMP Info Header - \n");         
	printf("  FIleName   : %s\n",READ_FILE_NAME2);         
	printf("  Infosize   : %d\n", BmpInfoHd.biSize);         
	printf("  Width      : %d\n", BmpInfoHd.biWidth);         
	printf("  Height     : %d\n", BmpInfoHd.biHeight);         
	printf("  Planes     : %d\n", BmpInfoHd.biplanes);         
	printf("  Bitcount   : %d\n", BmpInfoHd.biBitCount);         
	printf("  Compressin : %d\n", BmpInfoHd.biCompression);         
	printf("  Sizeimage  : %d\n", BmpInfoHd.biSizeImage);         
	printf("  XPelsPerMeter : %d\n", BmpInfoHd.biXPelsPerMeter);         
	printf("  YPelsPerMeter : %d\n", BmpInfoHd.biYPelsPerMeter);         
	printf("  ClrUsed       : %d\n", BmpInfoHd.biClrUsed);         
	printf("  ClrImportant  : %d\n", BmpInfoHd.biClrImportant);           
	retval=fread(ImageBuffer, sizeof(ImageBuffer), 1, fp);         
	if(retval<0) {                 
		perror("Buffer Empty or Error Occured!");                 
		exit(1);         
	}
           
	retval=sizeof(ImageBuffer);           
	
	for(h=0;h<(HEIGHT/2);h++) {                 
		for(w=0;w<(WIDTH*3);w++) {                         
			Temp = ImageBuffer[(h*(WIDTH*3))+w];                         
			ImageBuffer[(h*(WIDTH*3))+w] = ImageBuffer[(retval-((h+1)*(WIDTH*3)))+w];
                        ImageBuffer[(retval-((h+1)*(WIDTH*3)))+w] = Temp;                 
		}         
	}           

	// For RGB Sorting         
	for(i=0;i<retval;i+=3) {                         
		Temp = ImageBuffer[i+2];                         
		ImageBuffer[i+2] = ImageBuffer[i];                         
		ImageBuffer[i]=Temp;         
	}           

	if((fb_fd = open("/dev/fb0",O_RDWR))<0) {                 
		perror("Frame Buffer Open Error!\n");                 
		exit(1);         
	}           

	if((check=ioctl(fb_fd,FBIOGET_VSCREENINFO,&fvs))<0) {                 
		perror("Get Information Error - VSCREENINFO!");                 
		exit(1);         
	}           

	if(fvs.bits_per_pixel != 32) {                 
		perror("Unsupport Mode. 32Bpp Only!\n");exit(1);         
	}           

	if(lseek(fb_fd, 0, SEEK_SET) < 0) {                 
		perror("LSeek Error!!\n");                 
		exit(1);         
	}           
	
	posx1=0;         
	posx2=WIDTH;         
	posy1=0;         
	posy2=HEIGHT;           

	for(repy=posy1;repy<posy2;repy++) {                 
		offset = repy * fvs.xres * (32/8) + posx1 * (32/8);                 
		if(lseek(fb_fd, offset, SEEK_SET) < 0) {                         
			perror("LSeek Error!!!");                         
			exit(1);                 
		}                 
		for(repx = posx1;repx < posx2; repx++) {                         
			pixel = makepixel(ImageBuffer[pixcnt++],ImageBuffer[pixcnt++],\
                        ImageBuffer[pixcnt++]);                         
			write(fb_fd, &pixel,(32/8));                 
		}         
	}         
	close(fb_fd);           

	fclose(fp);           
	
	
}     

/* Function Descrpt */ 
unsigned char quit = 0;

void user_signal1(int sig) 
{
	quit = 1;
}

int main(void)
{
	int i;
	int dev;
	int buff_size;
	int image;
	int a;
	unsigned char push_sw_buff[MAX_BUTTON];//button open error

	dev = open("/dev/fpga_push_switch", O_RDWR);

	if (dev<0){
		printf("Device Open Error\n");
		close(dev);
		return -1;
	}
	
	(void)signal(SIGINT, user_signal1);
        treestar_bmp();
	buff_size=sizeof(push_sw_buff);
	printf("Press <ctrl+c> to quit. \n");
	while(!quit){
		usleep(400000);
		read(dev, &push_sw_buff, buff_size);
		if(push_sw_buff[0]) {while(1){
			
				fbrect(255,255,255,5);//white
				read(dev, &push_sw_buff, buff_size);
				if(push_sw_buff[0]==0) break;
				}
			
		}

		else if(push_sw_buff[1]){while(1){
			
				fbrect(0,255,255,2);//greenblue
				read(dev, &push_sw_buff, buff_size);
				if(push_sw_buff[1]==0) break;
				}
			
		}
		else if(push_sw_buff[2]){while(1){
			
				fbrect(255,0,0,2);//red
				read(dev, &push_sw_buff, buff_size);
				if(push_sw_buff[2]==0) break;
				}
		}
		else if(push_sw_buff[3]){while(1){
			
				fbrect(254,204,0,2);//yellow
				read(dev, &push_sw_buff, buff_size);
				if(push_sw_buff[3]==0) break;
				}
		}
		else if(push_sw_buff[4]) {
			treestar_bmp();//reset
			}
	}
	close(dev);
}

