#include<bits/stdc++.h>
//#define int long long

typedef long long ll;
typedef long double ld;

using namespace std;

void solve(){
    ll n;
    cin >> n;
    ll gcd = n;
    for(ll i = 2; i < 2000000; i++){
        if(n % i == 0){
            gcd = __gcd(i, gcd);
            if(n / i != 1)
            gcd = __gcd(n / i, gcd);
        }
    }
    cout << gcd;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test =  1;
    //cin >> test;
    while(test--){
        solve();
    }
}
