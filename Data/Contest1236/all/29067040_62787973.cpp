//
// Created by StupidTurtle on 2019/10/17.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007;
ll fpow(ll a,ll n){
    ll res=1ll;
    while(n){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}
int main(){
    ll n,m;scanf("%lld%lld",&n,&m);
    printf("%lld\n",fpow((fpow(2ll,m)-1ll+mod)%mod,n));
    return 0;
}