
#include <stdio.h>
#include "mine_sweeper.h"
#include <unistd.h>

int menu(char *str)
{
    int option ;
    puts(str) ;
    printf("请输入你的选择:") ;
    int status = scanf("%d", &option) ;
    FFLUSH ;
    if( status == 0 )
        option = -1 ;
    return option ;
}


void submenu()
{
    int subre ;

REOPT :
    subre = menu( submenustr ) ;
    switch(subre){
        case 1 :
            config(9, 9, 10) ;
            break ;
        case 2 :
            config(16, 16, 40) ;
            break ;
        case 3 :
            config(30, 25, 99) ;
            break ;
        case 4 :
            printf("请输入自定义参数:\n") ;
            int parl, parw, parn ;
            printf("Length Width MineNumber\n") ;
            int status = scanf("%d%d%d", &parl, &parw, &parn) ;
            FFLUSH ;
            if( status != 3 || parl <= 0 || parw <= 0 || parn <=0){
                fprintf(stderr, "错误的输入！恢复默认设置！\n") ;
                config(9, 9, 10) ;
            }else{
                config(parl, parw, parn) ;
                printf("配置已经修改\n") ;
                sleep(1) ;
            }
            break ;
        case 5 :
            break ;

        default :
            printf("无效的选项!请重新选择\n") ;
            goto REOPT ;
            break ;
    }

}
