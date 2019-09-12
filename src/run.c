#include "mine_sweeper.h"
#include <stdio.h>
#include <ctype.h>


void ClickNone(int, int) ;

int MoniClick(int i, int j)
{
    if( G_field[i][j] == 1 ){
        printf("-------------------------------------------------\n") ;;
        printf("    Booooooooom!!!\n") ;
        printf("    触碰到地雷，游戏结束!\n") ;
        printf("-------------------------------------------------\n") ;;
        printAnswer() ;
        return 1;
    }else if( G_output[i][j] == SYMBOL_STAR ){

        int cnt = MineCount(i, j) ;
        if( cnt ){
            G_output[i][j] = cnt + '0' ;
        }else{
            G_output[i][j] = ' ' ;
            ClickNone(i, j) ;
        }
        touched++ ;
        printOutput() ;
    }else{
        printf("区域%c%d已被探测\n", j + 'A', i + 1 ) ;
    }
    return 0 ;
}

int GetLocate()
{
    int ret = 0 ;
    int c ;
    int num = 0;
    extern int Row, Col ;
    extern int Effect  ;
    extern int toExit  ;

    while((c = getchar())){

        if(isalpha(c)){
            if( !scanf("%d", &num) ){
                goto ERROR ;
            }
            Col = toupper(c) - 'A' ;
            Row = num - 1;
            Effect = EffectLocate(Row , Col) ;
            /*printf("得到坐标%c%d\n", c, num) ;*/
            //如果函数返回1，则输入的坐标不在范围内
            if( !Effect ){
                printf("-------------------------------------------------\n") ;;
                printf("\n    无效的坐标%c%d被忽略\n", c, num) ;
                printf("-------------------------------------------------\n") ;;
            }   
            break ;
        }
        else if(c == '-'){
            int d = getchar() ;
            if( d == '0' + 1 ){
                toExit = -1 ;
                ret = 0 ;
                break ;
            }        
            /*ungetc(d, stdin) ;*/
            goto ERROR ;
        }
        else if( c == ' ' || c == '\t' ){
            continue ;
        }else if( c == '\n' ){
            ungetc(c, stdin) ;
            ret = 1 ;
            break ;
        }else{
            goto ERROR ;
        }
    }

    return ret ;

ERROR :
    printf("-------------------------------------------------\n") ;;
    printf("\n    错误的输入！\n    请确认你要探测的区域\n") ;
    printf("-------------------------------------------------\n") ;;
    ret = 1 ;
    return ret ;

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
        if( EffectLocate(i, j) ){
                //再检测该位置是否被探测过
            if( G_output[i][j] == '*' ){
                int cnt = MineCount(i, j) ;
                if( cnt ){
                    G_output[i][j] = cnt + '0' ;
                }else{
                    /*printf("坐标%d %d周围没有雷\n", i, j) ;*/
                    G_output[i][j] = ' ' ;
                    ClickNone(i, j) ;
                } 
                touched++ ;
            }
        }
    }
    }
}
