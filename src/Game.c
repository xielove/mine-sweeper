#include "mine_sweeper.h"
#include <stdio.h>
#include <stdlib.h>

int square     = 0 ;
//雷区的面积(方块的个数)
int touched    = 0 ;
//已经被探测的区域
int **G_field  = NULL ;
//指向雷区
int **G_output = NULL ;
//指向输出数组


int Effect = 0 ;
int toExit = 0 ;
int Row = 0 ;
int Col = 0 ;

void GameStart()
{
    //初始化必要参数，存储空间
    InitAll() ;
    printOutput(G_output) ;

    //进入事件循环
    while(1){

        printf("请选择你要探索的区域(或-1退出):") ; 

        while(!GetLocate()){
            if( toExit == -1 ){
                free(G_field) ;
                free(G_output);
                return ;
            }
            /*printf("Effect = %d\n", Effect) ;*/
            int status ;
            if( Effect )
                status = MoniClick(Row, Col) ;
                /*printf("\n点击坐标%c%d\n", This.y + 'A', This.x + 1) ;*/
            if( status )
                return ;
            if(touched == square - G_mnum){
                printSuc() ;
                return ;
            }
        }
        EmptyBuffer() ;
    }
}
