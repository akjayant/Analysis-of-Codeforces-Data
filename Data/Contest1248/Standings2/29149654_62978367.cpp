#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m;
vector <int> P;
vector <int> Q;
long long answer;

void In()
{
	cin >> n;
	P.resize(n);
	for (int i = 0; i < n; i++) cin >> P[i];
	cin >> m;
	Q.resize(m);
	for (int i = 0; i < m; i++) cin >> Q[i];
}

void Solve()
{
	long long p_even = 0;
	for (int i = 0; i < n; i++) if (P[i] % 2 == 0) p_even++;
	long long p_odd = n - p_even;
	long long q_even = 0;
	for (int i = 0; i < m; i++) if (Q[i] % 2 == 0) q_even++;
	long long q_odd = m - q_even;
	answer = p_even * q_even + p_odd * q_odd;
}

void Out()
{
	cout << answer << endl;
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