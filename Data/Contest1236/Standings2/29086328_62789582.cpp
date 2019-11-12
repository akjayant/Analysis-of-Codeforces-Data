#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
#define keep_calm_and_become_violet ios_base::sync_with_stdio(0)
#define utochka_po_imeni_johnathan_livingston cin.tie(0);
 
using namespace std;

long long mod = 1e9 + 7;

long long bp(long long a, long long p) {
	if (p == 0) return 1;
	else if (p % 2 == 1) {
		return a * bp(a, p - 1) % mod;
	} else {
		long long m = bp(a, p / 2) % mod;
		return m * m % mod;
	}
}

void solve(int qq) {
	long long n, m; cin >> n >> m;
	cout << bp((bp(2, m) + mod - 1) % mod, n) % mod << endl;

}
 
int main()
{
    keep_calm_and_become_violet;
    utochka_po_imeni_johnathan_livingston;
 
    int t;
   	//cin >> t;
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}

