#include "mine_sweeper.h"
#include <stdio.h>
#include <ctype.h>


void ClickNone(int, int) ;

void CheckArea(Coordinate* fp)
{
    int i = fp->x ;
    int j = fp->y ;
    if( field[i][j] == 1 ){
        printf("\nBooooooooom!!!") ;
        printf("触碰到地雷，游戏结束!\n") ;
        printAnswer() ;
        return ;
    }else{
        printf("已点击方块\n") ;
        printf("输出:\n") ;
        int cnt = MineCount(i, j) ;
        if( cnt ){
            output[i][j] = cnt + '0' ;
        }else{
            output[i][j] = ' ' ;
            ClickNone(i, j) ;
        }
        touched++ ;
        printOutput() ;
    }

}


void GameStart()
{
    printOutput(output) ;

    while(1){

        printf("输入-1结束游戏\n") ;
        printf("==>请输入坐标(例E1):") ; 

        int num ;
        int c ;
        Coordinate click ;

        while((c = getchar()) != '\n' && c != EOF){
            if(isspace(c)){
                continue ;
            }else if(isalpha(c)){
                if( !scanf("%d", &num) )
                    goto ERROR_INPUT ;
                click.y = toupper(c) - 'A' ;
                click.x = num - 1;
                int status = EffectCoordinates(click.x, click.y) ;
                if(status){
                    printf("%d,%d\n", click.x, click.y) ;
                    CheckArea(&click) ; 
                }
                else
                    printf("无效的坐标%c%d被忽略\n", c, num) ;
            }else
                goto ERROR_INPUT ;

        }

        FFLUSH ;
        if(touched == square - mnum){
            printf("恭喜通关本次游戏\n") ;
            printAnswer() ;
        }
        continue ;

ERROR_INPUT :
        printf("输入错误\n请检查你的输入\n") ;
        FFLUSH ;
    }
}



/*
   A   B   C
   +---+---+---+
   1 |   |   |   |
   +---+---+---+
   2 |   | * |   |
   +---+---+---+
   3 |   |   |   |
   +---+---+---+

*/

//探测到周围没有地雷时，进行一个递归探测(如B2)
void ClickNone(int frow, int fcol)  //输入参数为周围九宫格内没有地雷的位置
{
    int i, j ;

    //两个for循环表示九宫格
    for(i = frow - 1 ; i <= frow + 1 ; i++){
    for(j = fcol - 1 ; j <= fcol + 1 ; j++){
        //检测九宫格位置是否出界
        if( EffectCoordinates(i, j) ){
                //再检测该位置是否被探测过
            if( output[i][j] == '*' ){
                int cnt = MineCount(i, j) ;
                if( cnt ){
                    output[i][j] = cnt + '0' ;
                }else{
                    /*printf("坐标%d %d周围没有雷\n", i, j) ;*/
                    output[i][j] = ' ' ;
                    ClickNone(i, j) ;
                } 
                touched++ ;
            }
        }
    }
    }
}
