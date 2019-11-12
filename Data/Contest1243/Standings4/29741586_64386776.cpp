#include <bits/stdc++.h>

using namespace std;

void solve()
{
	string s, t;
	int n;
	
	cin >> n;
	cin >> s >> t;
	
	set <int> d1[30];
	set <int> d2[30];
	
	for(int i = 0; i < n; i++)
	{
		d1[s[i] - 'a'].insert(i);
		d2[t[i] - 'a'].insert(i);
	}
	
	vector <pair <int, int> > res;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= 'z' - 'a'; j++)
		{
			while(d1[j].size() != 0 && *d1[j].begin() <= i)
				d1[j].erase(*d1[j].begin());
			
			while(d2[j].size() != 0 && *d2[j].begin() <= i)
				d2[j].erase(*d2[j].begin());
		}
		
		if(s[i] == t[i])
			continue;
		
		int p = s[i] - 'a';
		
		if(d1[p].size() == 0 && d2[p].size() == 0)
		{
			cout << "NO\n";
			return ;
		}
		
		if(d1[p].size() == 0)
		{
			int pos = *d2[p].begin();
			d2[p].erase(*d2[p].begin());
			
			res.push_back({pos, pos});
			
			d1[t[pos] - 'a'].insert(pos);
			d2[s[pos] - 'a'].insert(pos);
			d1[s[pos] - 'a'].erase(pos);
			
			swap(s[pos], t[pos]);
		}
		
		if(d1[p].size() != 0)
		{
			int pos = *d1[p].begin();
			
			d1[p].erase(*d1[p].begin());
			
			res.push_back({pos, i});
			
			d1[t[i] - 'a'].insert(pos);
			d1[s[i] - 'a'].erase(pos);
			
			swap(s[pos], t[i]);
		}
	}
	cout << "YES\n";
	
	cout << res.size() << '\n';
	
	for(auto i : res)
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';
}

main()
{
	int t;
	cin >> t;
	
	while(t--)
		solve();
}