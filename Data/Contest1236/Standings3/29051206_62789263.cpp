//scnucjh
#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;


typedef long long ll;
const ll M = 1e9+7;
ll mod_pow(ll a,ll k,ll MOD) {
    ll res=1;
    while(k) {
        if(k&1) res=res*a%MOD;
        a=a*a%MOD;
        k/=2;
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
#endif
    ll n,m;
    cin>>n>>m;
    ll t = mod_pow(2,m,M);
    ll ans = mod_pow((t-1+M)%M,n,M);
    cout<<ans<<endl;
	return 0;
}

