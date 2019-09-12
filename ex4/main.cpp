#include<bits/stdc++.h>

using namespace std;

long double* jacobi( long double* x ){

    x[0] = (           -0.1*x[1] +1.2*x[2] -1.9*x[3] +2.2*x[4] -2.1*x[5] +0.9*x[6] -4.5 ) / 10.8;
    x[1] = (  2.3*x[0]           +2.8*x[2] +0.1*x[3] -1.9*x[4]           -0.3*x[6] +1.5 ) / 14;
    x[2] = ( -0.2*x[0] +1.5*x[1]           +2*x[3]   +0.4*x[4] +3*x[5]   -1.7*x[6] -4.6 ) / 9.1;
    x[3] = ( -1.8*x[0] -1.1*x[1] -2.1*x[2]           -0.5*x[4] -1.8*x[5] +2*x[6]   -1.3 ) / 16.5;
    x[4] = ( -0.9*x[0] -1.4*x[1] +x[2]     -0.1*x[3]           +0.2*x[5] +2.7*x[6] -2   ) / 8.1;
    x[5] = (  2.7*x[0] +2.3*x[1] -2.7*x[2] -2.5*x[3] -0.2*x[4]           +2.8*x[6] -0.6 ) / 17.1;
    x[6] = ( -1.5*x[0] +1.1*x[1] -1.4*x[2] +1.6*x[3] -1.1*x[4] +0.3*x[5]           -2.4 ) / 9.6;

    return x;
}

void printX( long double* x ){

    for( int i = 0; i < 7; i++ ){
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

}

int main(){

    long double* x;
    int n;

    x = (long double*) malloc( sizeof( long double ) * 7 );

    cin >> x[0];
    cin >> x[1];
    cin >> x[2];
    cin >> x[3];
    cin >> x[4];
    cin >> x[5];
    cin >> x[6];
    cin >> n;

    for( int i = 2; i <= n; i++ ){

        x = jacobi( x );
        cout << "X" << i << ":" << endl;
        printX( x );

    }

    return 0;
}