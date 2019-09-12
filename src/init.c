#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mine_sweeper.h"

static void InitArray(int ***pf, int sym)
{
    for(int i = 0 ; i < G_length; i++)
    for(int j = 0 ; j < G_width ; j++)
        (*pf)[i][j] = sym ;
}

static void InitField()
{
    InitArray(&G_field, 0) ;
    int *pmine = G_field[0] ;
    srand( (unsigned)time(NULL) ) ;
    for(int i = 0 ; i < G_mnum; i++){
        int rdm = rand() % (square) ;
        if(pmine[rdm] == 0)  //不是雷的位置放入0
            pmine[rdm] = 1 ; //在雷所在的位置放入1
        else
            i-- ;
    }
}

static void InitOutput()
{
    InitArray(&G_output, SYMBOL_STAR) ;
}

void InitAll()
{
    square = G_length * G_width ;
    Creat() ;
    InitField() ;
    InitOutput();
}
