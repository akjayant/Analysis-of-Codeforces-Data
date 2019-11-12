#include<bits/stdc++.h>
#define ll long long
#define N 1000050
#define pi acos(-1)
#define mod 1000000007
#define endl '\n'
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
using namespace std;

ll t,n,k,l,r,a[500][500],b[N],ans,sum;
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
	cin>>n;
	ans=1;
	for(int i=0;i<n;i++)
	if(i%2)
	for(int j=0;j<n;j++)
	a[i][j]=ans++;
	else
	for(int j=n-1;j>=0;j--)
	a[i][j]=ans++;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<a[j][i]<<' ';
		cout<<endl;
	}
	return 0;
}