#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define int long long
#define ll long long
#define EPS 0.00000000000001
#define ld long double
#define inf 10000000002
#define N 2001

int dp[32][2][2][2][2];
int l,r;


int rec(int i,int c1,int c2,int c3,int c4)
{
	// cerr << i << " " << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
	if(i == -1)
		return 1;
	if(dp[i][c1][c2][c3][c4] == -1)
	{
		int& ans  = dp[i][c1][c2][c3][c4];
		ans = 0;
		int rbit = (r & (1 << i)) > 0;
		int lbit = (l & (1 << i)) > 0;
		//case zero zero
		// cerr << lbit << " " << rbit << endl;
		int can[2][2];
		memset(can,0,sizeof(can));
		{
			//r zero
			if(c2 == 0)
			{
				can[1][0] = (lbit == 0);
			}
			else
				can[1][0] = 1;
			//r one
			if(c1 == 0)
			{

				can[1][1] = rbit;
			}
			else
			{
				can[1][1] = c1 | rbit;
			}
		}
		{
			if(c4 == 0)
			{
				can[0][0] = (lbit == 0);
			}
			else
				can[0][0] = 1;
			//r one
			if(c3 == 0)
			{
				can[0][1] = rbit;
			}
			else
			{
				can[0][1] = c3 | rbit;
			}
		}
		// for(int i = 0;i < 2;i++)
		// {
		// 	for(int j = 0;j < 2;j++)
		// 	{
		// 		cerr << can[i][j] << " " ;
		// 	}
		// 	cerr << endl;
		// }
		if(can[1][0] and can[0][0])
		{
			ans += rec(i - 1,c1 | rbit,c2,c3 | rbit,c4);
		}
		if(can[0][1] and can[1][0])
		{
			ans += rec(i - 1,c1 | rbit,c2,c3,c4 | (!lbit));
		}
		if(can[0][0] and can[1][1])
		{
			ans += rec(i - 1,c1,c2 | (!lbit),c3 | rbit,c4);
		}
		// cerr << i << " " << c1 << " " << c2 << " " << c3 << " " << c4 << " " << ans << endl;
		return ans;
	}
	else
		return dp[i][c1][c2][c3][c4];
}


int solve(int a,int b)
{
	memset(dp,-1,sizeof(dp));
	l = a;
	r = b;
	return rec(30,0,0,0,0);

}

int32_t main()
{
	IOS;
	#ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int a,b;
   		cin >> a >> b;
   		cout << solve(a,b) << endl;;
   	}



	return 0;
}