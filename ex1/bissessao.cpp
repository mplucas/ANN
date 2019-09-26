#include <bits/stdc++.h>
using namespace std;

double funcao( double num ){

    return pow( num, 5 ) - ( 4 * num ) - 3;

}

int main(int argc, const char** argv) {

    double a, b, p, neg, pos;
    int n, i;

    cout << "PROGRAMA DA BISSESSÃO:" << endl << endl;
    cout << "Informe o valor de a:";
    cin >> a;
    
    cout << "Informe o valor de b:";
    cin >> b;

    if( funcao( a ) * funcao( b ) >= 0 ){
        cout << "f(a)*f(b) deve ser negativo.";
        return 0;
    }
    
    cout << "Informe quantas interações da bissessão:";
    cin >> n;

    if( funcao( a ) > 0 ){
        pos = a;
        neg = b;
    }else{
        pos = b;
        neg = a;
    }

    for( i = 0; i < n; i++ ){

        p = ( pos + neg ) / 2;

        if( funcao( p ) > 0 ){
            pos = p;
        }else{
            neg = p;
        }

    }

    cout << "Ponto médio é igual a: " << p;

    return 0;

}