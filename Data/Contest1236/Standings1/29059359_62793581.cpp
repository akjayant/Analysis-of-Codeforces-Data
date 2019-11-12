#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define int long long
#define ll long long
#define EPS 0.00000000000001
#define ld long double
#define inf 1000000
#define N 2005

int v[N][N];

int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
  	int n;
  	cin >> n;

  	for(int j = 0;j < n;j++)
  	{
  		int add,start;
  		if((j & 1) == 0)
  		{
  			add = 1;
  			start = j * n;
  		}
  		else
  		{
  			add = -1;
  			start = (j + 1) * n - 1;
  		}
  		for(int i = 0;i < n;i++)
  		{
  			v[i][j] = start;
  			start += add;
  		}

  		
  	}
  	for(int i = 0;i < n;i++)
  	{
  		for(int j = 0;j < n;j++)
  			cout << v[i][j] + 1 << " " ;
  		cout << endl;
  	}
    return 0;
}
 
 