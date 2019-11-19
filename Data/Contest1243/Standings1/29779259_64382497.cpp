#include <bits/stdc++.h>
#define FOR(i, u, v) for (int i = u; i <= v; i++)
#define FORD(i, v, u) for (int i = v; i >= u; i--)
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define mod 1000000007

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("INP.TXT", "r")) {
		freopen("INP.TXT", "r", stdin);
    }
    long long n;
    cin >> n;
    long long k = n;
    FOR(i, 2, sqrt(n)) {
        if (n % i == 0) {
            k = __gcd(k, 1ll*i);
            k = __gcd(k, 1ll*n/i);
        }
    }
    cout <<k;
}

