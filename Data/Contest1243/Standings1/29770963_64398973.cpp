#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false) ;
    cin.tie(0) ;


    int T ;
    cin >> T ;
    for(int t2 = 0; t2 < T; t2++){

        int n ;
        cin >> n ;
        int ans = 0 ;
        string s, t ;
        cin >> s >> t ;
        bool can = 1 ;
        vector<pair<int, int> > moves ;
        for(int i = 0; i < n; i++){

          if(s[i] == t[i])
            continue ;
          int ind = i ;
          while(ind < n && s[ind] != t[i])
            ind++ ;
          if(ind == n){

            ind = i+1 ;
            while(ind < n && t[ind] != t[i])
              ind++ ;
            if(ind == n){

              can = 0 ;

            }else{

              ans++ ;
              moves.push_back({i+1, ind+1}) ;
              swap(s[i], t[ind]) ;

            }

          }else{

            ans++ ;
            ans++ ;
            moves.push_back({ind+1,i+2}) ;
            swap(s[ind], t[i+1]) ;
            moves.push_back({i+1,i+2}) ;
            swap(s[i], t[i+1]) ;

          }

        }
        if(can){
          cout << "Yes\n" << ans << '\n' ;
          for(auto i:moves)
            cout << i.first << ' ' << i.second << '\n' ;
        }else{

          cout << "No\n" ;

        }

    }

}
