#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
 
    float num, result, derivada, p;
    int i, n;

    scanf( "%f", &num );
    scanf( "%i", &n );

    for( i = 2; i <= n; i++ ){
        
        result = pow( num, 3 ) - ( 4 * num ) - 1;
        derivada = 3 * pow( num, 2 ) - 4;
        p = num - ( result / derivada );
        printf( "\n p%i: %f", i, p );
        num = p;

    }
    
    return 0;
}