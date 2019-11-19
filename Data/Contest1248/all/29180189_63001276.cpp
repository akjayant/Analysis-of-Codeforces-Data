#include <iostream>
#include <cstdio>
#define R register

using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int n, m;
long long f[N];
int main()
{
	cin >> n >> m;
	f[0] = 2, f[1] = 2;
	for(R int i = 2; i <= max(n,m); i++)
		f[i] = (f[i-1] + f[i-2]) % mod;
	cout << ((f[n] + f[m] - 2 + mod) % mod) << endl;
	return 0;
}