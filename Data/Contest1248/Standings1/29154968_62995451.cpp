/**
 *    author:  MySakure
 *    created: 20.10.2019 17:23:10       
**/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int maxn=1e5+10;
int a[maxn],n,m;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef mysakure 
	//freopen("in1.txt","r",stdin);
#endif
	cin>>n>>m;
	a[1]=1,a[2]=2;
	for(int i=3;i<=max(n,m);++i){
		a[i]=(a[i-1]+a[i-2])%mod;
	}
	a[0]=1;
	int cur=a[n];
	for(int i=1;i<m;++i){
		cur+=a[i-1];
		cur%=mod;
	}
	cout<<(2*cur%mod)<<endl;



	


	return 0;
}

