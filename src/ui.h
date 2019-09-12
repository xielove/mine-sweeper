#ifndef __UI__H
#define __UI__H

#define EmptyBuffer() {\
    int c ;\
    while((c = getchar()) != '\n' && c != EOF) ;\
}
extern char *MenuStr ;
extern char *SubMenuStr ;
extern char *HelpStr ;
extern char *ByeStr ;

void GameStart() ;

int GetOpt() ;

void SubMenu() ;
//雷区长度及宽度，累的数量
//获取参数
int GetParm(int *, int *, int *) ;
//配置全局参数
void ParmConf(int , int, int) ;

//打印函数
void printHelp() ;
void printBye() ;
void printConf() ;
void printMenu() ;
void printSubMenu() ;

#endif
