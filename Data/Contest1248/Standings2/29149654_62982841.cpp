#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
vector <long long> sticks;
long long answer;

void In()
{
	cin >> n;
	sticks.resize(n);
	for (int i = 0; i < n; i++) cin >> sticks[i];
}

void Solve()
{
	sort(sticks.begin(), sticks.end());
	long long sum = 0;
	long long total = 0;
	for (int i = 0; i < n/2; i++) sum += sticks[i];
	for (int i = 0; i < n; i++) total += sticks[i];
	answer = sum * sum + (total - sum) * (total - sum);
}

void Out()
{
	cout << answer << endl;
}

int main()
{__
	In();
	Solve();
	Out();
}