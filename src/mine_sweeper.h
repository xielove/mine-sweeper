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


#define FFLUSH {\
    int c ;\
    while((c = getchar()) != EOF && c != '\n') ;\
}

typedef struct{
    int x ;
    int y ;
}Coordinate ;


extern int length ;
extern int width ;
extern int mnum ;
extern int touched ;
extern int square ;
extern int **field ;
extern int **output ;

extern char *menustr ;
extern char *submenustr ;
extern char *helpstr ;

void creat() ;
void InitAll() ;

int EffectCoordinates(int fi, int fj) ;
int MineCount(int fi, int fj) ;

int menu(char *str) ;
void printAnswer() ;
void printOutput() ;

void config(int, int, int) ;
void submenu() ;

#endif
