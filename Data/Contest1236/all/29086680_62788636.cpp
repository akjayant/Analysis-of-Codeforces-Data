#include <iostream>
using namespace std;

#define ll long long
#define mod 1000000007

ll pow_mod(ll x, ll y){
    ll res=1;
    while(y){
        if(y&1){
            res*=x;
            res%=mod;
        }
        y>>=1;
        x*=x;
        x%=mod;
    }
    return res;
}

int main(){
    ll n,m;
    cin>>n>>m;
    ll res=pow_mod(2,m);
    res--;
    if(res<0) res+=mod;
    res=pow_mod(res,n);
    cout<<res<<"\n";
    return 0;
}