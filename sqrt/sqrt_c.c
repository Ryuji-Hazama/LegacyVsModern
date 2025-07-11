#include <stdio.h>

/* - - - - - - - - - - - -*
 * Square Root of Integer *
 * - - - - - - - - - - - -*/

// Subroutine SQRT

int manual_sqrt(int A){
    int C, D;

    // If zero or below

    if(A == 0){
        // Root 0 is 0
        return 0;
    }else if(A < 0){
        // In case of negative number
        return -1;
    }
    
    // Root calculation

    C = A;

    do{
        D = (C + A / C) / 2;

        if(C == D){
            return D;
        }
        
        C = D;
    }while(1);
}

// Entry point

void main(void){
    int L = 5;

    // Test
    L = manual_sqrt(L);
}