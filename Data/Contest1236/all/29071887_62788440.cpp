#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi acos(-1)
ll mod = 1000000007;
using namespace std;

ll power(ll a, ll b, ll c){
    ll res = 1;
    while(b > 0){
        if(b & 1){
            res = (res * a) % c;
        }
        a = (a * a) % mod;
        b = b / 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;
    cout << power((((power(2ll, m, mod) - 1)%mod + mod) % mod), n, mod);
    return 0;
}
