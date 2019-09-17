#include<bits/stdc++.h>
using namespace std;

long double* jacobi( long double* x ){

    long double v[7];

    for( int i = 0; i < 7; i++ ){
        v[i] = x[i];
    }

    x[0] = (           -0.1*v[1] +1.2*v[2] -1.9*v[3] +2.2*v[4] -2.1*v[5] +0.9*v[6] -4.5 ) / 10.8;
    x[1] = (  2.3*v[0]           +2.8*v[2] +0.1*v[3] -1.9*v[4]           -0.3*v[6] +1.5 ) / 14;
    x[2] = ( -0.2*v[0] +1.5*v[1]           +2*v[3]   +0.4*v[4] +3*v[5]   -1.7*v[6] -4.6 ) / 9.1;
    x[3] = ( -1.8*v[0] -1.1*v[1] -2.1*v[2]           -0.5*v[4] -1.8*v[5] +2*v[6]   -1.3 ) / 16.5;
    x[4] = ( -0.9*v[0] -1.4*v[1] +v[2]     -0.1*v[3]           +0.2*v[5] +2.7*v[6] -2   ) / 8.1;
    x[5] = (  2.7*v[0] +2.3*v[1] -2.7*v[2] -2.5*v[3] -0.2*v[4]           +2.8*v[6] -0.6 ) / 17.1;
    x[6] = ( -1.5*v[0] +1.1*v[1] -1.4*v[2] +1.6*v[3] -1.1*v[4] +0.3*v[5]           -2.4 ) / 9.6;

    return x;
}

void printX( long double* x ){
    for( int i = 0; i < 7; i++ )
        cout << "x" << i + 1 << " = " << x[i] << endl;
}

int main(){

    long double* x;
    int n;

    x = (long double*) malloc( sizeof( long double ) * 7 );

    for( int i = 0; i < 7; i++ )
        cin >> x[i];

    cin >> n;

    for( int i = 2; i <= n; i++ ){

        x = jacobi( x );
        cout << "X" << i << ":" << endl;
        printX( x );

    }

    return 0;
}