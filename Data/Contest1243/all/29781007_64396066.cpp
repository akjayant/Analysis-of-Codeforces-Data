#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const ll maxn = 200015;
const ll inf = 0x3f3f3f3f;

ll n;
int m;

int main(){
#ifndef ONLINE_JUDGE
    #define TASK "abc"
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
#endif
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
    cin >> n;
    ll p = -1, tem = n, sl = 0;
    for(ll i = 2; i * i <= tem; ++i){
        if (n % i == 0){
            m ++;
            if (p != -1) {
                cout << 1;
                return 0;
            }
            while (tem%i == 0) tem /= i;
            p = i;
        }

    }

    if (p != -1 && tem > 1) {
        cout << 1;
        return 0;
    }
    if (p == -1) {
        cout << n;
        return 0;
    }
    cout << p;
return 0;
}
