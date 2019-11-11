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
	string a;
	cin >> a;
	long long ku = 1, kn = 1;
	long long k = 1;
	vector <long long> C(a.size() + 1, 1);
	for (int i = 2; i < a.size() + 1; i++)
		C[i] = (C[i - 1] + C[i - 2]) % mod;
	char ls = '1';
	for (int i = 0; i < a.size(); i++)
	{
		if ((a[i] == 'w') || (a[i] == 'm'))
		{
			k = 0;
			break;
		}
		if (a[i] != ls)
		{
			if (ku != 0)
				k *= C[ku];
			if (kn != 0)
				k *= C[kn];
			k %= mod;
			kn = 0;
			ku = 0;
		}
		if (a[i] == 'u')
			ku++;
		if (a[i] == 'n')
			kn++;
		ls = a[i];
	}
	if (kn > 0)
		k *= C[kn];
	if (ku > 0)
		k *= C[ku];
	k %= mod;
	cout << k;
	return 0;
}