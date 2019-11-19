#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<int> nextRand(0, (int)1e9);
long long mod = 1000000007;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	vector <long long> X(n), Y(n);
	vector <long long> C(n);
	vector <long long> K(n);
	long long v = 0, e = 0;
	queue <int> V;
	queue <int> E;
	vector <bool> T(n, true);
	vector <bool> Vis(n, false);
	vector <long long> G(n, 0);
	for (int i = 0; i < n; i++)
		cin >> X[i] >> Y[i];
	long long m = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> C[i];
		if (C[i] < C[m])
			m = i;

	}
	for (int i = 0; i < n; i++)
		cin >> K[i];
	long long s = 0;
	for (int i = 0; i < n; i++)
	{
		s += C[m];
		Vis[m] = true;
		if (T[m])
		{
			v++;
			V.push(m + 1);
		}
		/*else
		{
			e++;
			E.push(m + 1);
		}*/
		int tm = m;
		for (int j = 0; j < n; j++)
		{
			if (C[j] > (abs(X[m] - X[j]) + abs(Y[m] - Y[j])) * (K[m] + K[j]))
			{
				C[j] = (abs(X[m] - X[j]) + abs(Y[m] - Y[j])) * (K[m] + K[j]);
				T[j] = false;
				G[j] = m;
			}
			if (!Vis[j])
			{
				if (tm == m)
					tm = j;
				else
					if (C[j] < C[tm])
						tm = j;
			}
		}
		if (!(T[tm]) && (!Vis[tm]))
		{
			e++;
			E.push(tm + 1);
			E.push(G[tm] + 1);
		}
		m = tm;
	}
	cout << s << '\n';
	cout << v << '\n';
	while (!V.empty())
	{
		cout << V.front() << ' ';
		V.pop();
	}
	cout << '\n' << e << '\n';
	while (!E.empty())
	{
		cout << E.front() << ' ';
		E.pop();
		cout << E.front() << '\n';
		E.pop();
	}
	return 0;
}