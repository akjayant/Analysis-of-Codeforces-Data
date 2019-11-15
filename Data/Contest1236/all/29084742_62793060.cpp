#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll MOD=1e9+7;
ll qpow(ll x,ll y,ll mod)
{
	ll temp=x;
	ll ans=1;
	while(y){
		if(y&1) ans=(ans*temp) % mod;
		temp=(temp*temp)%mod;
		y>>=1;
	}
	return ans;
}
int a[505][505];
int main()
{
	int n;
	cin>>n;
	int c=1;
	for(int i=1;i<=n;i++) //第i列 
	{
		if(i%2==1){
			for(int j=1;j<=n;j++)
				a[j][i]=c++;
		}else{
			for(int j=n;j>=1;j--)
				a[j][i]=c++;			
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(j==n) cout<<a[i][j]<<"\n";
			else cout<<a[i][j]<<" ";
	}
	return 0;
}