#include <bits/stdc++.h>
 
using namespace std;
#define fr(i,x,y) for(int i=x;i<y;i++)
#define int long long
const int N=1e3,INF=1e9,MOD=1e9+7;
int mas[N];
int ans[N][N];
 main()
{
	int n;
	cin>>n;
	int q=1;
	fr(j,0,n)
	{
		if(j%2==0)
		{
			fr(i,0,n)
			{
				ans[i][j]=q;
				q++;
			}
		}
		else
		{
			for(int i=n-1;i>=0;i--)
			{
				ans[i][j]=q;
				q++;
			}
		}
	}
	fr(i,0,n)
	{
		fr(j,0,n)
		{
			cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
	}
}