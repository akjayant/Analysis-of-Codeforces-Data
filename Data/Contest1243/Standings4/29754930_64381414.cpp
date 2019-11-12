#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
string s, t;
bool answer;

void In()
{
	cin >> n >> s >> t;
}

bool Solve()
{
	int different = 0;
	for (int i = 0; i < n; i++) if (s[i] != t[i])
	{
		different++;
		if (different == 3) return false;
	}
	if (different == 1) return false;
	
	different = 0;
	char first, second;
	for (int i = 0; i < n; i++) if (s[i] != t[i])
	{
		different++;
		if (different == 1)
		{
			first = s[i];
			second = t[i];
		}
		else
		{
			if (s[i] == first && t[i] == second) return true;
		}
	}
	return false;
}

void Out()
{
	cout << (answer ? "Yes" : "No") << endl;
}

int main()
{__
	int t = 1;
	cin >> t;
	while (t--)
	{
		In();
		answer = Solve();
		Out();
	}
}