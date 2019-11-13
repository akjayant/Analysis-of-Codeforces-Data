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
			for ( j = i+1 ; j < n; j++ )
			{
				if ( s2[i] == s2[j] and s1[i] == s1[j] )
				{
					swap(s1[i],s2[j]);
					break;
				}
			} 
			break;
		}
		if ( s1 != s2 )
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
}