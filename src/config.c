#include <stdio.h>
#include "ui.h"

int G_length = 9 ;
//雷区的长度
int G_width  = 9 ;
//雷区的宽度
int G_mnum   = 10 ;
//雷的数量

void printConf()
{
    printf("-------------------------------------------------\n") ;
    printf("|   雷区长度为: %2d\n", G_length) ;
    printf("|   雷区宽度为: %2d\n", G_width)  ;
    printf("|   雷的数量为: %2d\n", G_mnum)   ;
    printf("-------------------------------------------------\n") ;

}
void ParmConf(int flength, int fwidth, int fmnum)
{
    G_length = flength ;
    G_width  = fwidth  ;
    G_mnum   = fmnum   ;
}

int GetParm(int *len, int *wid, int *num)
{
    int ret = 0 ;
    int status = scanf("%d %d %d", len, wid, num) ;
    EmptyBuffer() ;
    if( status != 3 ){
        ret = 1 ;
    }else{
        if(*len < 3 || *wid < 3 || *num < 0)
            ret = 1 ;
        if(*len > 40 || *wid > 26 ){
            ret = 1 ;
            printf("请注意参数的范围\n") ;
        }

        if( *wid * (*len) < *num * 5 ){
            printf("雷的数量不宜多于雷区的20%%\n") ;
            ret = 1 ;
        }
    }
    return ret ;
}
