#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#define int long long
using namespace std;
const int mod=1e9+7;
int a,b,p,ans;
int binpow(int x,int n){
	if(n==0) return 1;
	if(n==1) return x%mod;
	int mid=binpow(x,n/2);
	if(n%2==0) return mid*mid%mod;
	else return mid*mid%mod*x%mod;
}
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>a>>b;
	p=binpow(2,b)-1;
	ans=binpow(p,a);
	cout<<ans;
}