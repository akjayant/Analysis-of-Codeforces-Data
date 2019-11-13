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
int a[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	ll ans=q_pow(2,m)-1;
	cout<<q_pow(ans,n)<<endl;
} 
