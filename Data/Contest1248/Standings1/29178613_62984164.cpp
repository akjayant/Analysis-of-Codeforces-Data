#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <assert.h>

using namespace std;

#define ll long long
#define ull unsigned long long
const ll INF = 1e18;
const double PI = acos(-1.0);

const int MAX_N = 100005;
int mas[MAX_N];

int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
	sort(mas, mas + n);

	ll a = 0, b = 0;
	for (int i = 0; i < n / 2; i++)
	{
		a += mas[i];
	}
	for (int i = n / 2; i < n; i++)
	{
		b += mas[i];
	}
	ll res = a * a + b * b;
	cout << res;

	//system("pause");
	return 0;
}