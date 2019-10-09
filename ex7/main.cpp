#include <bits/stdc++.h>
using namespace std;

vector<float> multPxP( vector<float> p1, vector<float> p2 ){

    int n1 = p1.size();
    int n2 = p2.size();

    vector<float> ans( n1 + n2 - 1, 0 );

    for( int i = 0; i < p1.size(); i++ ){

        for( int j = 0; j < p2.size(); j++ ){

            ans[ ((n1-1) - i) + ((n2-1) - j) ] += p1[i] * p2[j];

        }

    }

    return ans;

}

vector<vector<float>> calculaLs( vector<vector<float>> ps ){

    vector<vector<vector<float>>> ds;
    vector<vector<float>> ls;

    for( int i = 0; i < ps.size(); i++ ){

        ds.push_back(vector<vector<float>>());

        for( int j = 0; j < ps.size(); j++ ){

            if( i == j )
                continue;

            ds[i].push_back( { 1 / (ps[i][0] - ps[j][0]), -ps[j][0] / (ps[i][0] - ps[j][0]) } );

        }

        vector<float> ans = ds[i][0];

        for( int j = 1; j < ds[i].size(); j++  ){

            ans = multPxP( ans, ds[i][j] );

        }

        ls.push_back( ans );

    }

    return ls;

}

vector<float> multPxY( vector<float> p, float y ){

    vector<float> ans( p.size() );

    for( int i = 0; i < p.size(); i++ ){
        ans[i] = p[i] * y;
    }

    return ans;

}

// vetores devem ter o mesmo tamanho
vector<float> addPxP( vector<float> p1, vector<float> p2 ){

    vector<float> ans( p1.size() );

    for( int i = 0; i < p1.size(); i++ ){
        ans[i] = p1[i] + p2[i];
    }

    return ans;

}

int main(){
    
    vector<vector<float>> ps;
    float x, y;
    vector<float> p;

    while( scanf( "%f %f", &x, &y ) != EOF ){

        p.push_back( x );
        p.push_back( y );

        ps.push_back( p );

    }

    vector<vector<float>> ls;

    ls = calculaLs( ps );

    vector<float> ans( ls[0].size(), 0 );

    for( int i = 0; i < ls.size(); i++ ){

        ans = addPxP( ans, multPxY( ls[i], ps[i][1] ) );

    }

    for( int i = 0; i < ans.size(); i++ ){
        printf( "a%i: %.8f\n", i, ans[i]);
    }

    return 0;
}