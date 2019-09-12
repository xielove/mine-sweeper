#include "mine_sweeper.h"
#include <stdlib.h>
#include <stdio.h>

static const int Size_int   = sizeof(int) ;
static const int Size_int_p = sizeof(int*) ;

//分配雷区的存储
//存储结构为:
//----------------------------------------------------------------------------
//|        |        |        |        | ... |    |    |    |  ...  |    |    |
//----------------------------------------------------------------------------
//前面Size_int_p * lenth 个字节是length个指针
//后面分配length*G_width*Size_int个字节作为数据区
//其中length个指针分别指向含有width个int数据的一维数组
//从而模拟出一个二维数组
//
void Creat()
{
    //申请存储空间
    G_field  = (int **)malloc( G_length*Size_int_p + G_length*G_width*Size_int ) ;
    G_output = (int **)malloc( G_length*Size_int_p + G_length*G_width*Size_int ) ;
    if( G_field == NULL || G_output == NULL ){
        fprintf(stderr, "分配空间失败\n") ;
        exit(EXIT_FAILED) ;
    }
    for(int i = 0; i < G_length; i++){
        G_field[i]  = (int *)(G_field + G_length) + i * G_width ;
        G_output[i] = (int *)(G_output + G_length) + i * G_width ;
    }

}


#if 0

int main(int argc, const char *argv[])
{
    int **pp = NULL ;
    pp = Creat_Field(4, 4, pp ) ;
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            pp[i][j] = i + j ;
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", pp[i][j]) ;
        }
        printf("\n") ;
    }
    free(pp) ;
    return 0;
}

#endif
