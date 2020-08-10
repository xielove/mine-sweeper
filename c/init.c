#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mine_sweeper.h"

//初始化输出数组
static void InitArray(int ***pf, int sym)
{
    for(int i = 0 ; i < length; i++)
    for(int j = 0 ; j < width ; j++)
        (*pf)[i][j] = sym ;
}

static void InitField()
{
    InitArray(&field, 0) ;

    int *pmine = field[0] ;
    srand( (unsigned)time(NULL) ) ;
    for(int i = 0 ; i < mnum; i++){
        int rdm = rand() % (square) ;
        if(pmine[rdm] == 0)  //不是雷的位置放入0
            pmine[rdm] = 1 ; //在雷所在的位置放入1
        else
            i-- ;
    }
}

void InitAll()
{
    square = length * width ;
    creat() ;
    InitField() ;
    InitArray(&output, SYMBOL_STAR) ;
}
