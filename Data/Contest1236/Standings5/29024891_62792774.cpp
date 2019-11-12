#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
const int N=1e5+10;

typedef long long ll;
const ll mod=1e9+7;

ll n,m;

ll pow_mod(ll a, ll n, ll m)
{
    long long ans = 1;
    while(n){
        if(n&1){
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        n >>= 1;
    }
    return ans;
}



int main(){
	scanf("%lld %lld",&n,&m);
	ll ans=pow_mod(2,m,mod);
	ans--;
	ans=pow_mod(ans,n,mod);
	ans=ans%mod;
	printf("%lld\n",ans);
	return 0;
} 