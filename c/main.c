#include <stdio.h>
#include <stdlib.h>
#include "mine_sweeper.h"
#include <unistd.h>

extern void GameStart() ;
int main(int argc, const char *argv[])
{

    do{
        int re ;
        re = menu( menustr ) ;
        switch(re){
            case 1 :
                InitAll() ;
                printf("开始游戏\n") ;
                GameStart() ;
                goto EXIT ;

            case 2 :
                printf("当前配置为:\n") ;
                printf("length     = %d\n", length) ;
                printf("width      = %d\n", width) ;
                printf("MineNumber = %d\n", mnum) ;
                submenu() ;                
                break ;

            case 3 :
                puts(helpstr) ;
                printf("\n请按任意键返回") ;
                FFLUSH ;
                break ;

            case 4 :
                goto EXIT ;

            default :
                printf("无效的选项!请重新选择\n\n") ;
                sleep(1) ;
                break ;
        }
    }while(1) ;
    
EXIT:
    free(field) ;
    free(output) ;
    return 0;
}
