#include<bits/stdc++.h>

#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(v) (int) v.size()

using namespace std;

const int N = 1e6 + 5;

bool prime[N];

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}

void precalc() {
    fill(prime, prime + N, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (prime[i] && i * i < N) {
            for (int j = i * i; j < N; j += i) {
                prime[j] = false;
            }
        }
    }
}

main() {
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precalc();
    int n;
    cin >> n;
/*    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);
    vector<vector<int>> c(n);
    for (int i = 0; i < n; ++i) {
        c[i].pb(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (abs(i - j) > 1 && n % abs(i - j) == 0 && ans[i] != ans[j]) {
                int old = ans[i];
                for (int x : c[old]) {
                    ans[x] = ans[j];
                    c[ans[j]].pb(x);
                }
                c[old].clear();
            }
        }
    }
    set<int> S;
    for (int x : ans) {
        S.insert(x);
    }*/
    int answ = 1;
    if (is_prime(n)) {
        answ = n;
    } else {
        for (int d = 2; d * d <= n; ++d) {
            if (n == d || n % d != 0 || !prime[d]) continue;
            int n1 = n;
            while (n1 % d == 0) n1 /= d;
            if (n1 == 1) {
                answ = d;
                break;
            }
        }
    }
    cout << answ << "\n";

    return 0;
}
