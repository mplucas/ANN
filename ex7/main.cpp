#include <bits/stdc++.h>
using namespace std;

vector<double> multPxP( vector<double> p1, vector<double> p2 ){

    int n1 = p1.size();
    int n2 = p2.size();

    vector<double> ans( n1 + n2 - 1, 0 );

    for( unsigned int i = 0; i < p1.size(); i++ ){

        for( unsigned int j = 0; j < p2.size(); j++ ){

            ans[ ((n1-1) - i) + ((n2-1) - j) ] += p1[i] * p2[j];

        }

    }

    return ans;

}

vector<vector<double>> calculaLs( vector<vector<double>> ps ){

    vector<vector<vector<double>>> ds;
    vector<vector<double>> ls;

    for( unsigned int i = 0; i < ps.size(); i++ ){

        ds.push_back(vector<vector<double>>());

        for( unsigned int j = 0; j < ps.size(); j++ ){

            if( i == j )
                continue;

            vector<double> aux;

            aux.push_back( 1 / (ps[i][0] - ps[j][0]) );
            aux.push_back( -ps[j][0] / (ps[i][0] - ps[j][0]) );

            //printf("%f %f %lu %f %i %f %f\n", aux[0], aux[1], aux.size(), (ps[i][0] - ps[j][0]), j, ps[i][0], - ps[j][0] );

            ds[i].push_back(aux);

        }

        vector<double> ans = ds[i][0];

        for( unsigned int j = 1; j < ds[i].size(); j++  ){

            ans = multPxP( ans, ds[i][j] );

        }

        ls.push_back( ans );

    }

    return ls;

}

vector<double> multPxY( vector<double> p, double y ){

    vector<double> ans( p.size() );

    //printf("%f\n", y);

    for( unsigned int i = 0; i < p.size(); i++ ){
        ans[i] = p[i] * y;
    }

    return ans;

}

// vetores devem ter o mesmo tamanho
vector<double> addPxP( vector<double> p1, vector<double> p2 ){

    vector<double> ans( p1.size() );

    //printf( "teste\n" );
    for( unsigned int i = 0; i < p1.size(); i++ ){
        ans[i] = p1[i] + p2[i];
        //printf("%.8f %.8f %.8f\n",p1[i], p2[i], ans[i]);
    }

    return ans;

}

int main(){

    setbuf(stdout, NULL);
    
    vector<vector<double>> ps;
    double x, y;

    while( scanf( "%lf %lf", &x, &y ) != EOF ){

        vector<double> p;

        p.push_back( x );
        p.push_back( y );

        ps.push_back( p );

    }

    // for( auto p:ps ){
    //     printf("%f %f %lu\n", p[0], p[1], p.size());
    // }

    vector<vector<double>> ls;

    ls = calculaLs( ps );

    // for( auto l:ls ){
    //     for(auto d:l)
    //         printf("%f ", d);
    //     printf("%lu\n", l.size());
    // }

    vector<double> ans( ls[0].size(), 0 );

    for( unsigned int i = 0; i < ls.size(); i++ ){

        ans = addPxP( ans, multPxY( ls[i], ps[i][1] ) );

    }

    for( unsigned int i = 0; i < ans.size(); i++ ){
        printf( "a%i: %.8f\n", ans.size() - 1 - i, ans[i]);
    }

    return 0;
}