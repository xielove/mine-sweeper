
#include <stdio.h>
#include "ui.h"
#include <unistd.h>

int GetOpt()
{
    //设置默认返回值为0
    int option = 0 ;

    scanf("%d", &option) ;
    EmptyBuffer() ;

    return option ;
}


void SubMenu()
{

REOPT :
    printSubMenu() ;
    int opt = GetOpt() ;

    switch( opt ){
        case 1 :
            ParmConf(9, 9, 10) ;
            break ;

        case 2 :
            ParmConf(16, 16, 40) ;
            break ;

        case 3 :
            ParmConf(30, 25, 99) ;
            break ;

        case 4 :
            printf("-------------------------------------------------\n") ;
            printf("|   请依次输入雷区的长度，宽度及雷的数量\n") ;
            printf("|   3<= length <=40\n") ;
            printf("|   3<= width  <=26\n") ;
            printf("-------------------------------------------------\n") ;
            int status ;
            int len, wid, num ;
            status = GetParm(&len, &wid, &num) ;
            if( !status )
                ParmConf(len, wid, num) ;
            else{
                fprintf(stderr, "无效的参数！\n\n") ;
                goto REOPT ;
            }

            break ;

        case 5 :
            break ;

        default :
            printf("无效的选项!请重新选择\n") ;
            goto REOPT ;
    }

}
