#include <bits/stdc++.h>
typedef long long ll ;
using namespace std;

int main()
{
    ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

    int t ; cin >> t;

    while(t--){
            int n ; cin >> n ;
            string s; cin >> s ;

            int res = n ;

            for(int i = 0 ; i < n ; i++){
                   if(s[i] == '1'){
                         int c1 = (i + 1) * 2;
                         int c2 = (n - i) * 2;
                         res = max(res , max(c1 , c2));
                   }
            }

            cout << res << endl ;
    }

    return 0;
}
