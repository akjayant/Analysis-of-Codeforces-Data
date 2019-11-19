//Sometimes you just need cheese

#include<bits/stdc++.h>
using namespace std ;

const int maxn = 1e5+10 ;

int a[maxn] ;

int main(){

  ios::sync_with_stdio(false) ;
  cin.tie(0) ;

  int n ;
  cin >> n ;
  for(int i = 0; i < n; i++)
    cin >> a[i] ;
  sort(a,a+n) ;

  long long x = 0 ;
  long long y = 0 ;
  for(int i = 0; i < n; i++){

    if(i < n/2)
      x+=a[i] ;
    else
      y+=a[i] ;

  }
  cout << x*x+y*y << '\n' ;

}
