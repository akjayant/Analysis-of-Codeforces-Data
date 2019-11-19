#include<bits/stdc++.h>
#define ll long long
#define N 1000050
#define pi acos(-1)
#define mod 1000000007
#define endl '\n'
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
using namespace std;

ll t,n,k,wl,wr,l,r,a[N],ans[N],sum;
char s[N];

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	sum=n*(n+1)/2;
	k-=sum;
	if(k<0)
	{
		cout<<-1;
		return 0;
	}
	int v=n-1;
	for(int i=1;i<=n;i++)
	{
		if(k>=v)
		a[i+v]=1,ans[i]=i+v,k-=v,sum+=v;
		else
		{
			a[i+k]=1,ans[i]=i+k,sum+=k;break;
		}
		v-=2;
		if(v<=0)
		break;
	}
	cout<<sum<<endl;
	for(int i=1;i<=n;i++)
	cout<<i<<' ';
	cout<<endl;
	l=1;
	for(int i=1;i<=n;i++)
	if(ans[i])
	cout<<ans[i]<<' ';
	else
	{
		while(a[l])
		l++;
		cout<<l<<' ';
		l++;
	}
	return 0;
}
