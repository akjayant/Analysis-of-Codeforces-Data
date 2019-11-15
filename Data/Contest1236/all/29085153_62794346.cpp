#include <bits/stdc++.h>
#define pi acos(-1.0)
#define ll long long
#define lf double
#define ull unsigned long long
#define esp 1e-9
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define Pair pair<ll, ll>
#define It set<ll>::iterator
#define CLR(x, a) memset(x, a, sizeof(x))
    
using namespace std;

const ll N = 1e5+5, mod = 1e9+7;
ll n, m;

ll qmod(ll a, ll b){
    ll ans = 1;
    a = a%mod;
    while (b){
        if(b&1 == 1)
            ans = ans*a%mod;
        a = a*a%mod;
        ans %= mod;
        b >>= 1;
    }
    return ans%mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	ll tmp = qmod(2, m)%mod;
	tmp = (tmp+mod-1)%mod;
	cout<<qmod(tmp, n)%mod<<endl;
	
	return 0;
}