#include <bits/stdc++.h>

using namespace std;

void solve()
{
	string s, t;
	int n;
	
	cin >> n;
	cin >> s >> t;
	
	vector <int> pos;
	
	for(int i = 0; i < n; i++)
		if(s[i] != t[i])
			pos.push_back(i);
	
	if(pos.size() == 0)
	{
		cout << "YES\n";
		return ;
	}
	
	if(pos.size() == 1 || pos.size() > 2)
	{
		cout << "NO\n";
		return ;
	}
	
	if(s[pos[0]] == s[pos[1]] && t[pos[0]] == t[pos[1]])
		cout << "YES\n";
	else
		cout << "NO\n";
}

main()
{
	int t;
	cin >> t;
	
	while(t--)
		solve();
}