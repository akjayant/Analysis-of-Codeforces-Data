#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int mod = (int)1e9 + 7;

ll ksm(ll x,ll y){
    ll res = 1;
    while(y){
        if(y%2){
            res = (res * x) % mod;
        }
        x = x * x % mod;
        y /= 2;
    }
    return res;
}



int main()
{
    int n , m;
    cin >> n >> m;

    ll ans = ksm(((ksm(2,m) - 1 + mod)%mod) , n);

    cout << ans;



    return 0;
}
