#include<bits/stdc++.h>
#define ll long long
#define N 1000050
#define pi acos(-1)
#define mod 1000000007
#define endl '\n'
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
using namespace std;

ll t,n,k,l,r,a[N],b[N],ans,sum;
char s[N];
ll p(ll a,ll k)
{
	ll ans=1,b=a;
	while(k)
	{
		if(k&1)
		ans=ans*b%mod;
		b=b*b%mod;
		k/=2;
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	cout<<p((p(2,k)+mod-1)%mod,n)%mod;
	return 0;
}