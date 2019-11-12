#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#define MAX 20
#define MOD 1000000007

ll pow_mod(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n&1) {
            res = (res * a) % MOD;
        }

        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	cout << pow_mod(pow_mod(2, m) - 1, n) << "\n";

	return 0;
}

