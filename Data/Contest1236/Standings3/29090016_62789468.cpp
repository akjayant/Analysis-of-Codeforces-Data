#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")
#include"bits/stdc++.h"
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define ends ' '
#define endl '\n'
#define pb emplace_back
#define x first
#define y second
#define pii pair<int, int>
#define sz(x) (int)(x).size()

const int prime = 1e9+7;

int mod (int a, int p = prime) {
	return (a%p + p) % p;
}

int xpo(int a, int b) {
	if(!b) {
		return 1;
	} else {
		int ret = xpo(mod(a*a), b/2);
		if(b&1) {
			ret = mod(ret * a);
		}
		return ret;
	}
}


int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	IOS;

	int n, m;
	cin >> n >> m;

	cout << xpo(xpo(2, m)-1, n);

	return 0;
}