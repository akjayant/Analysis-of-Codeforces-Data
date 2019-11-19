#include <bits/stdc++.h>
typedef long long ll ;
using namespace std;

int main()
{
    ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

    int t ; cin >> t;

    while(t--){
          int a , b , c , d , k ;
          cin >> a >> b >> c >> d >> k ;
          int c1 = (a / c) + (a % c != 0);
          int c2 = (b / d) + (b % d != 0);

          if(c1 + c2 > k) cout << -1 << endl ;
          else cout << c1 << " " << c2 << endl ;
    }

    return 0;
}
