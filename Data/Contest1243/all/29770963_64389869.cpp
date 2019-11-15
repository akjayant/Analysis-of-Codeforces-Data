// a nu cheeki reeki i v damke !

#include<bits/stdc++.h>
using namespace std ;

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define F first
#define S second

const int maxn = 1e3+10 ;

int charcnt[26] ;

int main(){

  ios::sync_with_stdio(false) ;
  cin.tie(0) ;

  int t ;
  cin >> t ;
  for(int T = 0; T < t; T++){

    int n ;
    string s, t ;
    cin >> n >> s >> t ;
    memset(charcnt, 0, sizeof charcnt) ;
    int can = 3 ;
    char sb = 1;
    char tb = 1;
    for(int i = 0; i < n; i++){

      if(s[i] != t[i]){

        if(sb != 1){

          if(can != 3){

            can = 0 ;
            break ;

          }


          can = 1 ;
          if(sb != s[i] || tb != t[i]){

            can = 0 ;

          }

        }

        sb = s[i] ;
        tb = t[i] ;

      }

    }
    if(can==1)
      cout << "Yes\n" ;
    else{
      cout << "No\n" ;
    }

  }

}
