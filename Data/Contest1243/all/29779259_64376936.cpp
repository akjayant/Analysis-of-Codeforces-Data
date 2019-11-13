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

int n, a[N];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("INP.TXT", "r")) {
		freopen("INP.TXT", "r", stdin);
    }
    int Tests; cin >> Tests;
    while (Tests--) {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
        sort(a+1, a+n+1);
        reverse(a+1, a+n+1);
        FORD(i, n, 1)
            if (a[i] >= i) {
                cout <<i<<endl;
                break;
            }
    }
}

