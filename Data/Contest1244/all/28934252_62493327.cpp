#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long double
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,x,y,b,k,i,j,a[100005],ve[100005]={0};
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<n/2;i++)
	{
		ve[i+1]+=a[i+1]-a[i];
	}
	for(i=n-1,j=1;i>=n/2;i--,j++)
	{
		ve[j]+=a[i]-a[i-1];
	}
	if(n%2==0)
	{
		ve[n/2]/=2;
	}
	x=a[0];
	y=a[n-1];
	for(i=1;i<=n/2;i++)
	{
	    //cout<<ve[i]<<endl;
		if(k>=i*ve[i])
		{
			k-=i*ve[i];
			x=a[i];
			y=a[n-1-i];
		}
		else
		{
			x+=k/i;
			cout<<y-x;
			return 0;
		}
	}
	cout<<0;
	return 0;
}