#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll fpow(ll x,ll p){
    ll res=1;
    while(p){
        if(p%2==1) res=res*x%MOD;
        p>>=1; x=x*x%MOD;
    }
    return res;
}
ll n,m;
int main(){
    scanf("%lld %lld",&n,&m);
    printf("%lld\n",fpow((fpow(2,m)-1+MOD)%MOD,n));
}