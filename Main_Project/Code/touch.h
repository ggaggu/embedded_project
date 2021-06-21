#ifndef TOUCH_H
#define TOUCH_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


typedef struct  touch_process_data__t
{
    unsigned    char    finger_cnt;
    unsigned    int     x1;
    unsigned    int     y1;
    unsigned    int     x2;
    unsigned    int     y2;
}touch_process_data_t;


#endif // TOUCH_H
