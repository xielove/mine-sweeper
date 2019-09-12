//UiPrint.c
//包含两个函数
//printHelp()和printBye()
//printConf() 在config.c中定义 
#include "ui.h"
#include <stdio.h>

static void printStr(char *str)
{
    puts(str) ;
}

void printHelp()
{
    printStr(HelpStr) ;
    printf("请按任意键返回") ;
    EmptyBuffer() ;
}

void printBye()
{
    printStr(ByeStr) ;
}

void printMenu()
{
    printStr(MenuStr) ;
    printf("请输入你的选择:") ;
}

void printSubMenu()
{
    printStr(SubMenuStr) ;
    printf("请选择相应的难度:") ;
}
