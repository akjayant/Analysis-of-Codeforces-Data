#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	
	int r, p, s;
	cin >> r >> p >> s;
	
	string S;
	cin >> S;
	
	int win = 0;
	
	vector <char> sol(n, 0);
	
	for(int it = 0; it < S.size(); it++)
	{
		char i = S[it];
		
		if(i == 'R' && p != 0)
		{
			p--;
			sol[it] = 'P';
			win++;
		}
		else
			if(i == 'P' && s != 0)
			{
				s--;
				win++;
				sol[it] = 'S';
			}
			else
				if(i == 'S' && r != 0)
				{
					win++;
					r--;
					
					sol[it] = 'R';
				}
	}
	
	if(win * 2 >= n)
	{
		cout << "YES\n";
		
		for(int i = 0; i < n; i++)
			if(sol[i] == 0)
			{
				if(r)
				{
					r--;
					sol[i] = 'R';
				}
				else
					if(p)
					{
						p--;
						sol[i] = 'P';
					}
					else
					{
						s--;
						sol[i] = 'S';
					}
			}
		
		for(auto i : sol)
			cout << i;
		
		cout << '\n';
	}
	else
	{
		cout << "NO\n";
	}
}

main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		solve();
	}
}