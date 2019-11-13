#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define ld long double
#define y1 asdfghjkl
#define ufo ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

mt19937_64 mt_rnd_64(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r){
    return (mt_rnd_64() % (r-l+1)) + l;
}

const ll MOD = 1e9 + 7;

ll n,m,ans;

ll binpow(ll x, ll y){
    ll res = 1;
    while(y){
        if(y & 1)
            res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return (res % MOD);
}

main()
{
    cin>>n>>m;
    ans = binpow(2,m)-1;
    ans = binpow(ans,n);
    cout<<ans;
}
