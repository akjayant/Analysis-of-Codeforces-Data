#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
string s, t;

int answer;
vector <pair<int,int>> swaps;

void In()
{
	cin >> n >> s >> t;
	answer = 0;
}

void Solve()
{
	bool found;
	for (int i = 0; i < n; i++) if (s[i] != t[i])
	{
		found = false;
		for (int j = i+1; j < n; j++) if (s[j] == s[i])
		{
			swaps.push_back({j,i});
			swap(s[j],t[i]);
			answer++;
			found = true;
			break;
		}
		if (found) continue;
		for (int j = i+1; j < n; j++) if (t[j] == s[i])
		{
			swaps.push_back({j,j});
			swap(s[j],t[j]);
			swaps.push_back({j,i});
			swap(s[j],t[i]);
			answer+=2;
			found = true;
			break;
		}
		if (!found)
		{
			answer = 0;
			return;
		}
	}
}

void Out()
{
	cout << (answer ? "Yes" : "No") << endl;
	if (answer) 
	{
		cout << answer << endl;
		for (int i = 0; i < answer; i++) 
			cout << swaps[i].first + 1 << " " << swaps[i].second + 1 << endl;
	}
	swaps.clear();
}

int main()
{__
	int t = 1;
	cin >> t;
	while (t--)
	{
		In();
		Solve();
		Out();
	}
}