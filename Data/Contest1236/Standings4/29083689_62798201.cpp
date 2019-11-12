#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+50;
const int mod=1e9+7;
ll q_pow(ll a,ll k)
{
	ll ans=1;
	while(k)
	{
		if(k & 1)
		{
			ans*=a;
			ans%=mod;
		}
		a*=a;
		a%=mod;
		k>>=1;
	}
	return ans;
}
int a[305][305];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int cnt=0;
	for(int j=1;j<=n;j++)
	{
		if(j%2)
		{
			for(int i=1;i<=n;i++)
			{
				a[i][j]=++cnt;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				a[i][j]=++cnt;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
} 
