#include<bits/stdc++.h>
#define FIN freopen("./C.in","r",stdin)
using namespace std;
typedef long long ll;
const ll maxn(1e5+5);
const ll mod(1e9+7);
ll T,n,a[maxn],m;
int main(){
#ifndef ONLINE_JUDGE
	FIN;
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	a[1]=2,a[2]=4;
	for(int i=3;i<maxn;i++){
		a[i]=(a[i-1]+a[i-2])%mod;
	}
	cout<<(a[n]+a[m]-2+mod)%mod<<"\n";
}
