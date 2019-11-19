#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=100005;
ll a[maxn];
int n;
ll k,diff;
void gol(int x)
{
	ll tp=(a[x+1]-a[x])*x;
	if(tp<=k)
	{
		k-=tp;
		diff-=a[x+1]-a[x];
	}
	else
	{
		ll tt=k/x;
		diff-=tt;
		k=0;
	}
}
void gor(int x)
{
	ll tp=(a[x]-a[x-1])*(n-x+1);
	if(tp<=k)
	{
		k-=tp;
		diff-=a[x]-a[x-1];
	}
	else
	{
		ll tt=k/(n-x+1);
		diff-=tt;
		k=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n;
	diff=a[n]-a[1];
	while(k>0 && l<r)
	{
		if(l-1<=n-r)
		{
			gol(l);
			l++;
		}
		else
		{
			gor(r);
			r--;
		}
	}
	cout<<diff<<endl;
}