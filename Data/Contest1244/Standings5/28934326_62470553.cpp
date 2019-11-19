#include<bits/stdc++.h>
using namespace std ;

const int maxn = 2e5+10 ;

int main(){

    ios::sync_with_stdio(false) ;
    cin.tie(0) ;

    int t ;
    cin >> t ;

    for(int T = 0; T < t; T++){

        int n ;
        cin >> n ;

        int f1 = -1 ;
        int l1 = -1 ;

        for(int i = 0; i < n; i++){

            char c ;
            cin >> c ;
            if(c == '1'){

                l1 = i ;
                if(f1 == -1)
                    f1 = i ;

            }

        }

        if (f1 == -1){

            cout << n << '\n' ;

        }else {

            cout << max(n-f1, l1+1)*2 << '\n' ;

        }

    }

}
