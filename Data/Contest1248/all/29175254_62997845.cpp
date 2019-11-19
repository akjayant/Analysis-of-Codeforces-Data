#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
const ll mod=1e9 + 7;

ll init(ll n){
    if(n==1)
        return 2;
    if(n==2)
        return 4;
    ll a = 2 , b = 4;
    n-=2;
    while(n-->0){
        ll c = (a+b)%mod;
        a = b;
        b = c;
    }
    return b;
}
ll calc(ll n){
    if(n==1)
        return 0;
    if(n==2)
        return 2;
    ll a = 1 , b = 2;
    n-=2;
    while(n-->0){
        ll c = (a+b)%mod;
        a = b;
        b = c;
    }
    ll ans = ( (2*b)%mod - 2 + mod)%mod;
    return ans;
}


int main(){
    ll r,c;
    cin>>r>>c;

    ll ans = init(r);
    ll a = ans;
    ll b = ( ans+2 )%mod;
    if(c==1)
        return cout<<a , 0;
    else if(c==2)
        return cout<<b , 0;
    ll sub = calc(r);
    c-=2;
    while(c-->0){
        ll n = ( (a+b)%mod -sub +  mod)%mod;
        a = b;
        b = n;
    }
    cout<<b;
}
