//Sometimes you just need cheese

#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e6+10 ;


int main(){

  ios::sync_with_stdio(false) ;
  cin.tie(0) ;

  int T ;
  cin >> T ;
  for(int t = 0; t < T; t++){

    int n ;
    cin >> n ;
    long long a = 0 ;
    long long b = 0 ;
    for(int i = 0 ; i < n; i++){

      int t ;
      cin >> t ;
      if(t%2)
        a++ ;
      else
        b++ ;

    }
    cin >> n ;
    long long c = 0;
    long long d = 0 ;
    for(int i = 0; i < n; i++){

      int t ;
      cin >> t ;
      if(t%2)
        c++;
      else
        d++ ;

  }
  cout << a*c + b*d << '\n' ;

  }

}
