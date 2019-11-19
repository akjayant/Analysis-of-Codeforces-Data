#include<bits/stdc++.h>
#define ll long long
#define N 200050
#define pi acos(-1)
#define mod 1000000007
#define endl '\n'
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
using namespace std;

ll t,n,k,wl,wr,l,r,a[N],ans,sum;
char s[N];

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	l=0;
	r=n-1;
	while(a[l]==a[l+1])
	l++;
	while(a[r]==a[r-1])
	r--;
	wl=l+1;
	wr=n-r;
	while(k>0&&l<r)
	{
		if(wl<wr)
		{
			if(k/wl<a[l+1]-a[l])
			{
				cout<<a[r]-a[l]-k/wl;
				return 0;
			}
			k-=wl*(a[l+1]-a[l]);
			l++;
			while(a[l]==a[l+1])
			l++;
			wl=l+1;
		}
		else
		{
			if(k/wr<a[r]-a[r-1])
			{
				cout<<a[r]-a[l]-k/wr;
				return 0;
			}
			k-=wr*(a[r]-a[r-1]);
			r--;
			while(a[r]==a[r-1])
			r--;
			wr=n-r;
		}
	}
	cout<<0;
	return 0;
}
