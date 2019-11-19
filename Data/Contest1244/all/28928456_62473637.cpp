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
    ll n , w  , p , d;
    cin >> n >> p >> w >> d;
    for(ll z = 0; z <= w + 10; ++z){
        if(z * d > p)continue;
        if((p - z * d) % w == 0){
            if(z + (p - z * d) / w > n)continue;
            cout << (p - z * d) / w << ' ' << z << ' '  << n - z - (p - z * d) / w;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
