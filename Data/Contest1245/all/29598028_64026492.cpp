#include <bits/stdc++.h>
using namespace std ;

const int N = 2005;

typedef pair<long long,pair<long long,long long>> iii ;

vector<iii> edges;
long long ci[N], ki[N] ;
long long xi[N], yi[N] ; 
long long fat[N]; 

void ini ( int n ){
     for ( int i = 0 ; i <= n ; ++i ) fat[i] = i ;
}

int fnd ( int x ) { 
     if ( fat[x] == x ) return x ;
     return fat[x] = fnd ( fat[x] ) ;
}    

void uni ( int x, int y ) {
     int compX = fnd ( x ) ;
     int compY = fnd ( y ) ;
     fat[compX] = compY ;
}


int main() { 
     int n;
     cin >> n ;
     ini ( n ) ;
     int magic = n ; 
     for ( int i = 0 ; i < n ; ++i ) cin >> xi[i] >> yi[i] ;
     for ( int i = 0 ; i < n ; ++i ) cin >> ci[i], edges.push_back ({ci[i], {magic, i}});
     for ( int i = 0 ; i < n ; ++i ) cin >> ki[i] ;
     for ( int i = 0 ; i < n ; ++i ) { 
          for ( int j = i+1 ; j < n ; ++j ) 
               edges.push_back ( {(ki[i]+ki[j])*((abs(xi[i]-xi[j])+abs(yi[i]-yi[j]))), {i,j}} ) ;    
     }
     sort ( edges.begin(), edges.end() ) ;
     long long optimallyW = 0 ;
     vector <long long> build ;
     vector<pair<long long,long long>> edg ; 
     for ( auto i:edges ) { 
          long long w = i.first ;
          int u = i.second.first, v = i.second.second ;
          if ( fnd(u) == fnd(v) ) continue ;
          uni ( u, v ) ;
          optimallyW += w;
          if ( max (u, v) == magic ) build.push_back ( min(u, v) ) ;
          else edg.push_back ( {u, v} );
     }
     cout << optimallyW << '\n';
     cout << build.size() << '\n';
     for( auto i:build) cout << i+1 << ' ';
     cout << '\n' << edg.size() <<'\n';
     for ( auto i:edg) cout << i.first+1 << ' '<< i.second+1 << '\n';
}