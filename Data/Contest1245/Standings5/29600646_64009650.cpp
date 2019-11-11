
// Created by RUPESH
// From https://blog.codingblocks.com/2019/setting-up-a-c-competitive-programming-environment

#include <bits/stdc++.h>


using namespace std;
using ll = long long;

#define pii pair<int,int>

int M = 1000000007;

ll val[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	val[0] = 1;
	val[1] = 1;
	for (int i = 2; i < 100005; ++i)
	{
		val[i] = (val[i-1] + val[i-2]) % M;
	}
	string s;
	cin >> s;
	ll answer = 1;
	char currentLetter = s[0];
	int letterCount = 1;

	if(currentLetter == 'm' || currentLetter == 'w') answer = 0;
	for (int i = 1; (i < s.length()) && (answer > 0); ++i)
	{
		if (s[i] == currentLetter) letterCount++;
		else{
			if (currentLetter == 'n' || currentLetter == 'u')
			{
				answer = (answer * val[letterCount]) % M;
				// cout << answer << letterCount;
			}
			currentLetter = s[i];
			letterCount = 1;
		}
		if(currentLetter == 'm' || currentLetter == 'w') answer = 0;
		// cout << currentLetter << " ";
	}
	if (currentLetter == 'n' || currentLetter == 'u')
	{
		answer = (answer * val[letterCount]) % M;
	}
	cout << answer << endl;
	return 0;
}