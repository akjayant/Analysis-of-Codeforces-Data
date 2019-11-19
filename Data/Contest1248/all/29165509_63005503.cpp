#include <bits/stdc++.h>
using namespace std;
typedef   long long ll;
ll mod=1000000007;
int main() {
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	ll n,m;
    cin>>n>>m;
    if(n>m)
	swap(n,m);
    ll ans[m+1];
    ans[1]=2;ans[2]=4;
    for(ll i=3;i<=m;i++)
	ans[i]=(ans[i-1]+ans[i-2])%mod;
    ll anss = ans[n],dif=0;
    for(ll i=2;i<=m;i++) {
        dif=(ans[i]-ans[i-1]+mod)%mod;
        anss=(anss+dif)%mod;
    }
    cout<<anss<<endl;
    return 0;
}
