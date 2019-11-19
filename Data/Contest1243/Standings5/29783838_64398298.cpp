#include <iostream>
#include <vector>
#include <algorithm>
const int MAXN = 1000000+9;
using namespace std;
long long n;
vector<long long> a;

int p[MAXN];

int FindSet(int u) {
	if (p[u] < 0) return u;
	return (p[u] = FindSet(p[u]));
}
void Union(int u, int v) {
	if (abs(p[u]) < abs(p[v])) {
		p[v] = p[v] + p[u];
		p[u] = v;
	}
	else
	{
		p[u] = p[v] + p[u];
		p[v] = u;
	}
}

int main() {
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	long long temp = n;
	for (long long i = 2; i*i <= n; ++i)
	{
		if (n%i == 0)
		{
			a.push_back(i);
			while (temp%i == 0)
				temp = temp / i;
		}
	}
	if (temp != 1)
		a.push_back(temp);

	if (a.size() ==1)
	{
		cout << a[0];
		return 0;
	}


	int m = a[0]; // <= 1000000


	int nColor = m;

	for (int i = 0; i < m; ++i)
		p[i] = -1;
	// Danh dau

	
	for (int i = 1; i < a.size(); ++i)
	{
		for (int j = 1; j <= m; ++j)
			if (j+a[i]<=n)
			{
			int u = FindSet(j%m);
			int v = FindSet(((long long )(j)+a[i])%m);
			if (u != v)
			{
				nColor--;
				Union(u, v);
			}
			}
		if (nColor == 1) break;
	}
	cout << nColor;
	return 0;
}