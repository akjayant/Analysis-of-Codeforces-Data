#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define endl '\n'

const int mod = 1e9 + 7;

int pow(int a, int n) {
	if (n == 0) return 1;
	if (n % 2 == 1) return a * pow(a, n - 1) % mod;
	else return pow(a * a % mod, n / 2);
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed << setprecision(20);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	int x = (mod + pow(2LL, m) - 1) % mod;
	cout << pow(x, n);
}