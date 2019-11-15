#include<iostream>
using namespace std;
typedef long long ll;

const int mod = 1000000007;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

int main(){
    ll n, m;
    cin >> n >> m;
    ll ans = modpow((modpow(2,m)-1+mod)%mod, n);
    cout << ans << endl;
    return 0;
}