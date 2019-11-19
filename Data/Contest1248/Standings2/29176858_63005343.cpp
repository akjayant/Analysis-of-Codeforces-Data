#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=110000;
const int p=1e9+7;
int n,m,f[maxn];

signed main()
{
	cin>>n>>m;
	f[1]=f[2]=1;
	for(int i=3;i<=max(n,m)+3;++i)
		f[i]=(f[i-1]+f[i-2])%p;
	int base=f[m+1]*2%p;
	for(int i=2;i<=n;++i){
		base=(base+f[i-1]*2)%p;
	}
	cout<<base;
}

