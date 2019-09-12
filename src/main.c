#include <stdio.h>
/*#include <stdlib.h>*/
#include "ui.h"
#include <unistd.h>

int main(int argc, const char *argv[])
{
    //主事件循环，接受用户输入
    while(1){
        printMenu() ;
        int opt = GetOpt() ; 

        switch( opt ){

            case 1 :
                printf("开始游戏\n") ;
                //进入游戏，在GameStart()中初始化
                //InitAll() ;
                GameStart() ;
                //goto EXIT ;

                printBye() ;
                return 0 ;

            case 2 :
                //打印当前配置
                printConf() ;
                putchar('\n') ;
                SubMenu() ;
                break ;

            case 3 :
                //打印帮助信息
                printHelp() ;
                break ;

            case 4 :
                //打印再见信息
                //退出程序
                printBye() ;
                return 0 ;

            default :
                printf("无效的选项!请重新选择\n\n") ;
                break ;
        }
    }
    
    return 0;
}


