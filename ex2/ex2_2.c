#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){

	float n1, n2, f1, f2, result;
	int i, t;
	
	scanf( "%f", &n1 );
	scanf( "%f", &n2 );
	scanf( "%i", &t );
	
	for( i = 3; i <= t; i++ ){
	 
		f1 = pow(n1,3) - (4 * n1) - 1;
	    	f2 = pow(n2,3) - (4 * n2) - 1;
	    	
	    	result = ((n1*f2)-(n2*f1))/(f2-f1);
	    	
	    	printf( "\np%i: %f", i, result );
	    	n1 = n2;
	    	n2 = result;
	    
	}
	
	return 0;

}
