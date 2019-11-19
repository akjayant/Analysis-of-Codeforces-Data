#include<bits/stdc++.h>
#define fi first
#define se second
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int a , b , c , d , k;
        cin >> a >> b >> c >> d >> k;
        int f = (a % c != 0) + a / c;
        int s = (b % d != 0) + b / d;
        if(f + s <= k)
            cout << f  << ' ' << s << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
