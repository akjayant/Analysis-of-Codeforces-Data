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
		vector<pii>ans;
		string s1,s2;
		cin >> s1 >> s2;
		for ( i = 0; i < n; i++ )
		{
			if ( s1[i] == s2[i] )
			{
				continue;
			}
			for ( j = i+1; j < n; j++ )
			{
				if ( s2[i] == s2[j] )
				{
					swap(s1[i],s2[j]);
					ans.pb({i,j});
					break;
				}
			}
			if ( j != n )
				continue;
			for ( j = i+1; j < n; j++ )
			{
				if ( s1[i] == s1[j] )
				{
					swap(s2[i],s1[j]);
					ans.pb({j,i});
					break;
				} 
			}
			if ( j != n )
			{
				continue;
			}
			for ( j = i+1; j < n; j++ )
			{	
				if ( s1[i] == s2[j] )
				{
					swap(s1[j],s2[j]);
					ans.pb({j,j});
					swap(s1[j],s2[i]);
					ans.pb({j,i});
					break;
				}
			}
			if ( j != n )
				continue;
			for ( j = i+1; j < n; j++ )
			{
				if ( s1[j] == s2[i] )
				{
					swap(s1[j],s2[j]);
					ans.pb({j,j});
					swap(s1[i],s2[j]);
					ans.pb({i,j});
					break;
				}
			} 
			if ( j == n )
			{
				cout << "No" << endl;
				break;
			} 
		}
		if ( i == n )
		{
			cout << "Yes" << endl;
			cout << ans.size() << endl;			
			for ( pii i : ans )
				cout << i.F+1 << " " << i.S+1 << endl;
		}
	}
}