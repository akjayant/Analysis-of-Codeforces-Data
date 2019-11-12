#include <bits/stdc++.h>
#define intt long long
#define pb push_back
#define endl '\n'
#define F first
#define S second
#define pii pair<int,int>
#define pil pair<int,intt>
#define pli pair<intt,int>
#define pll pair<intt,intt>
using namespace std;
int i,j;
int a[10005];
int main()
{
	int t;
	cin >> t;
	while ( t-- )
	{
		int n;
		cin >> n;
		for ( i = 1; i <= n; i++ )
		{
			cin >> a[i];
		}
		sort(a+1,a+n+1);	
		int l=1,r=1001,mid,best;
		while ( l < r )
		{
			mid = (l+r)>>1;
			for ( i = 1; i <= n; i++ )
			{
				if ( a[i] >= mid )
				{
					if ( n-i+1 >= mid )
					{
						best = mid;
						l = mid+1;
					}
					else
					{
						r = mid;
					}
					break;
				}
			}
			if ( i == n+1 )
				r = mid;
		}
		cout << best << endl;
	}
}