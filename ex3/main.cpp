#include<bits/stdc++.h>
#include<math.h>

using namespace std;

double g(double x){
    return 2 + ( 3.27 / ( pow( x, 2 ) + 6 ) );
}

double f(double x){
    return pow( x, 3 ) - 2 * pow( x, 2 ) + 6 * x - 15.27;
}

int main() {

    double x;
    int n;

    cin >> x;
    cin >> n;
    
    for( int i = 1; i <= n; i++ ){

        cout << "p" << i << ": " << x << endl;
        cout << "g(p" << i << ") = " << g(x) << endl;
        cout << "f(p" << i << ") = " << f(x) << endl;
        cout << "f(g(p" << i << ")) = " << f(g(x)) << endl << endl;
        x = g(x);

    }

    return 0;
}