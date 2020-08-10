#include "mine_sweeper.h"


int EffectCoordinates(int fi, int fj)
{
    int exit_code = NOT_EFFECT_COORDINATES ;

    if( fi < length && fi >= 0 )
    if( fj < width && fj >= 0 )
            exit_code =  EFFECT_COORDINATES ;
    
    return exit_code ;

}

int MineCount(int fi, int fj)
{
    int cnt = 0 ;
    int i, j ;
    
    for(i = fi - 1 ; i <= fi + 1 ; i++){
    for(j = fj - 1 ; j <= fj + 1 ; j++)
        if( EffectCoordinates( i, j ) && field[i][j] )
            cnt++ ;
    }

    return cnt ;
}


