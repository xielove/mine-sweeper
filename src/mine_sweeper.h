#ifndef __MINE_SWEEPER__H
#define __MINE_SWEEPER__H


#define EXIT_SUCCEED  0
#define EXIT_FAILED   1

#define NOT_EFFECT_COORDINATES 0
#define EFFECT_COORDINATES     1

//ASCII
#define SYMBOL_STAR   42
#define SYMBOL_SPACE  32
#define SYMBOL_MINE   36


#define EmptyBuffer() {\
    int c ;\
    while((c = getchar()) != EOF && c != '\n') ;\
}



//全局变量用'G_'作为前缀
//雷区的参数
extern int G_length ;   //雷区长度
extern int G_width ;    //雷区宽度
extern int G_mnum ;     //雷的数量
extern int **G_field ;  //指向雷区
extern int **G_output ; //指向输出

extern int touched ;
extern int square ;

void Creat() ;
void InitAll() ;

int EffectLocate(int , int) ;
int MineCount(int , int ) ;
int MoniClick(int , int) ;
int GetLocate()  ;

void printAnswer() ;
void printOutput() ;
void printSuc() ;

#endif
