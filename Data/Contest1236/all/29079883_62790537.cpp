#include<bits/stdc++.h>
using namespace std;

const int N=5e4+10;

typedef long long ll;
const ll mod=1e9+7;
ll quick_pow(ll a,ll b,ll mod) {
    ll res=1;
    a%=mod;
    while(b) {
        if(b&1)
            (res*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return res%mod;//mod==1
}

int main() {
    int n,m;
    cin>>n>>m;
    ll tmp=(quick_pow(2,m,mod)-1+mod)%mod;
    cout<<quick_pow(tmp,n,mod);
    return 0;
}
