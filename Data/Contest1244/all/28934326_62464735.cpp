#include<bits/stdc++.h>
using namespace std ;

const int maxn = 2e5+10 ;

int main(){

    ios::sync_with_stdio(false) ;
    cin.tie(0) ;

    int t ;
    cin >> t ;

    for(int T = 0; T < t; T++){

        int a, b, c, d, k ;
        cin >> a >> b >> c >> d >> k ;
        int pens = 0 ;
        while(pens*c < a)
            pens++ ;
        if((k-pens) * d >= b){

            cout << pens << ' ' << k-pens << '\n' ;

        }else{

            cout << "-1\n" ;

        }

    }

}
