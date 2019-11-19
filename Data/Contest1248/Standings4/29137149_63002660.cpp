#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define endl "\n"
 

int pow1(int n, int p)
{
	if(p==0)	return 1;
	int x=pow1(n, p/2);
	x=(x*x)%mod;
	if(p%2==0)
		return x;
	else
		return (x*n)%mod;
}

int c1=0;
int c2=0;

void func(int n, int m, int i, int j, vector<vector<int>> &v)
{
	if(i==n)
	{
		int f=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				// cout<<v[i][j]<<' ';
				int c=0;
				if(i-1>=0 && v[i-1][j]==v[i][j])
					c++;
				if(j-1>=0 && v[i][j-1]==v[i][j])
					c++;
				if(i+1<n && v[i+1][j]==v[i][j])
					c++;
				if(j+1<m && v[i][j+1]==v[i][j])
					c++;
				if(c>=2)
				{
					f=1;
					// break;
				}
			}
			// cout<<endl;
			// if(f)
			// 	break;
		}
		// cout<<f<<endl;
		if(f)
			c1++;
		else
			c2++;
		return;
	}
	v[i][j]=0;
	if(j==m-1)
	{
		func(n, m, i+1, 0, v);
	}
	else
	{
		func(n, m, i, j+1, v);
	}
	v[i][j]=1;
	if(j==m-1)
	{
		func(n, m, i+1, 0, v);
	}
	else
	{
		func(n, m, i, j+1, v);
	}
}

int32_t main()
{
	fast;
	int n, m;
	cin>>n>>m;
	vector<int> v1(n);
	vector<int> v2(m);
	for(int i=0;i<n;i++)
	{
		if(i==0)
			v1[i]=1;
		else if(i==1)
			v1[i]=2;
		else
			v1[i]=(v1[i-1]+v1[i-2])%mod;
	}
	for(int i=0;i<m;i++)
	{
		if(i==0)
			v2[i]=1;
		else if(i==1)
			v2[i]=2;
		else
			v2[i]=(v2[i-1]+v2[i-2])%mod;
	}
	int x=2*(v1[n-1]+v2[m-1])-2;
	x=x%mod;
	x+=mod;
	x=x%mod;
	cout<<x<<endl;
	return 0;
}