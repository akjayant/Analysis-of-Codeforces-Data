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
int main()
{
	int n;
	cin >> n;
	vector<int>v[n+1];
	for ( int k = 0; k < n; k++ )
	{
		if ( k&1 )
			j = n;
		else
			j = 1;
		for ( i = k*n+1; i <= (k+1)*n; i++ )
		{
			v[j].pb(i);
			if ( k&1 )
			{
				j--;
			}
			else
			{
				j++;
			}
		}
	}
	for ( i = 1; i <= n; i++ )
	{
		for ( int j : v[i] )
			cout << j << " ";
		cout << endl;
	}
}