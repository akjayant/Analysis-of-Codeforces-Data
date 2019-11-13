#include<bits/stdc++.h>

using namespace std;
#define debug(x) cout<<#x<<" is "<<x<<endl;
typedef long long ll;

const ll mod=1e9+7;

ll mypow(ll x,ll y){
    ll ac=1;
    while(y){
        if(y&1)ac=(ac*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return ac;
}

int main(){
    ll n,m;
    scanf("%lld%lld",&n,&m);
    printf("%lld\n",mypow((mypow(2ll,m)-1+mod*2)%mod,n));
    return 0;
}
