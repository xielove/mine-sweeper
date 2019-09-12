#include <stdio.h>
#include "mine_sweeper.h"

#define PATTERN_ONE {\
printf("    ") ;\
for(int i = 'A' ; i < 'A' + G_width; i++){\
    printf(" %c  ", (char)i ) ;\
}\
printf("\n") ;\
} 
#define PATTERN_TWO {\
printf("   +") ;\
for(int i = 'A' ; i < 'A' + G_width; i++){\
    printf("---+") ;\
}\
printf("\n") ;\
}
char *SucStr = "\
  _____                _   \n\
 / ____|              | |  \n\
| |  __ _ __ ___  __ _| |_ \n\
| | |_ | '__/ _ \\/ _` | __|\n\
| |__| | | |  __/ (_| | |_ \n\
 \\_____|_|  \\___|\\__,_|\\__|\n\
";
void printSuc() //完成游戏后输出
{
    puts(SucStr) ;
}

void printOutput()
{
    PATTERN_ONE ;
    PATTERN_TWO ;
    for(int i = 0 ; i < G_length ; i++){
        printf("%2d |" , i+1) ;
        for(int j = 0 ; j < G_width ; j++){
            printf(" %c |", G_output[i][j]) ;
        }

        printf("\n") ;
        PATTERN_TWO ;
    }
}

void printAnswer()//输出答案
{
    for(int i = 0 ; i < G_length ; i++){
    for(int j = 0 ; j < G_width ; j++){
        if( G_field[i][j] ){
            G_output[i][j] = SYMBOL_MINE ;
        }else{
            int cnt = MineCount(i, j) ; //mine_count():计算周围九宫格内的地雷数量
            if( !cnt )
                G_output[i][j] = SYMBOL_SPACE ;
            else
                G_output[i][j] = '0' + cnt ;
        }
    }
    }
    printOutput() ;
}
#if 0
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int **mine_field = NULL ;
    Init_Mine_Field(10, 10, 15, mine_field) ;
    print_answer(10, 10, mine_field) ;
    free(mine_field) ;

    return 0;
}
/*输出效果
    A   B   C   D   E   F   G   H   I
  +---+---+---+---+---+---+---+---+---+-
1 |   |   |   |   | 1 | × | 2 | 1 |   |
  +---+---+---+---+---+---+---+---+---+-
2 |   |   |   |   | 2 | 4 | × | 2 |   |
  +---+---+---+---+---+---+---+---+---+-
3 |   |   |   |   | 1 | × | × | 2 |   |
  +---+---+---+---+---+---+---+---+---+-
4 | 1 | 1 | 1 | 1 | 2 | 2 | 2 | 1 |   |
  +---+---+---+---+---+---+---+---+---+-
5 | × | 1 | 1 | × | 1 |   |   |   |   |
  +---+---+---+---+---+---+---+---+---+-
6 | 1 | 1 | 1 | 1 | 2 | 1 | 1 |   |   |
  +---+---+---+---+---+---+---+---+---+-
7 |   | 1 | 1 | 1 | 1 | × | 1 |   |   |
  +---+---+---+---+---+---+---+---+---+-
8 |   | 2 | × | 2 | 1 | 1 | 2 | 1 | 1 |
  +---+---+---+---+---+---+---+---+---+-
9 |   | 2 | × | 2 |   |   | 1 | × | 1 |
  +---+---+---+---+---+---+---+---+---+-
*/
#endif
