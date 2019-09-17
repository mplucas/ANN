#include<bits/stdc++.h>
using namespace std;

long double* gaussSeidel( long double* x ){

    x[0] = (           -0.2*x[1]           -x[3]     +0.9*x[4] +0.6 ) / 2.1;
    x[1] = (  0.5*x[0]           -1.9*x[2] -2.2*x[3] -1.9*x[4] -4.1 ) / 6.8;
    x[2] = (  2.9*x[0] -0.7*x[1]           +2.4*x[3] -1.6*x[4] +0.6 ) / 10.4;
    x[3] = (            2.2*x[1] +0.2*x[2]           -2*x[4]   -0.3 ) / 12.5;
    x[4] = ( -2.1*x[0] +2.9*x[1] -2.4*x[2] -0.9*x[3]           -2.9 ) / 10.5;

    return x;
}

void printX( long double* x ){
    for( int i = 0; i < 5; i++ )
        cout << "x" << i + 1 << " = " << x[i] << endl;
}

int main(){

    long double* x;
    int n;

    x = (long double*) malloc( sizeof( long double ) * 5 );

    for( int i = 0; i < 5; i++ )
        cin >> x[i];

    cin >> n;

    for( int i = 2; i <= n; i++ ){

        x = gaussSeidel( x );
        cout << "X" << i << ":" << endl;
        printX( x );

    }

    return 0;
}