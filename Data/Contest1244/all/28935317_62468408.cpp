#include<bits/stdc++.h>
using namespace std;

#define test() int t;cin>>t;for(int tc=1;tc<=t;tc++)
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define nl cout<<"\n"

const int MAXN = 1005;
const int LOGN = 20;
const int INF = 1e9;

int main()
{

	test()
	{
		int n;
		string s;
		cin>>n>>s;
		int mn = n+1, mx = -1;
		for(int i=0;i<n;i++)
		{
			if( s[i] == '1' )
			{
				mn = min(mn, i);
				mx = max(mx, i);
			}
		}
		int ans = max( 2*(mx+1) , 2*(n-mn) );
		ans = max(ans, n);
		cout<<ans,nl;
	}

	return 0;
}