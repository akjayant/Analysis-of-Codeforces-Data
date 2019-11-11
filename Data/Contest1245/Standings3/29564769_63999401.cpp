#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int mod = 1e9+7;

#undef int
int main()
{
#define int long long int
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		int n, a, b, c;
		map<char, int> m;
		string s;
		cin>>n>>m['R']>>m['P']>>m['S']>>s;
		string win = string(n, '#');
		int wins = 0;
		for(int i = 0;i<n;i++)
		{
			if(s[i] == 'R')
			{
				if(m['P'])
					win[i] = 'P', m['P']--, wins++;
			}
		}
		for(int i = 0;i<n;i++)
		{
			if(s[i] == 'P')
			{
				if(m['S'])
					win[i] = 'S', m['S']--, wins++;
			}
		}
		for(int i = 0;i<n;i++)
		{
			if(s[i] == 'S')
			{
				if(m['R'])
					win[i] = 'R', m['R']--, wins++;
			}
		}
		if(wins < n/2+n%2)
		{
			cout<<"NO"<<endl;
			continue;
		}
		for(int i = 0;i<n;i++)
		{
			if(win[i] == '#')
			{
				if(m['P'])
					win[i] = 'P', m['P']--;
				else if(m['R'])
					win[i] = 'R', m['R']--;
				else if(m['S'])
					win[i] = 'S', m['S']--;
			}
		}
		cout<<"YES"<<endl<<win<<endl;
	}

	return 0;
}