// a nu cheeki reeki i v damke !

#include<bits/stdc++.h>
using namespace std ;

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define F first
#define S second

const long long maxn = 1e3+10 ;

long long charcnt[26] ;

int main(){

  ios::sync_with_stdio(false) ;
  cin.tie(0) ;

  long long n ;
  cin >> n ;
  long long wow = -1 ;
  for(long long i = 2; i*i <= n; i++){

    if(n%i==0){

      if(wow != -1){

        cout << 1 ;
        return 0 ;

      }
      wow = i ;
      while(n%wow == 0){

        n/= wow ;

      }

    }

  }
  if(n != 1 && wow != -1){

    cout << 1 ;

  }else if(wow != -1){

    cout << wow ;

  }else{

    cout << n ;

  }

}
