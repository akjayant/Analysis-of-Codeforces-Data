#include <bits/stdc++.h>
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define sz(s) (int)(s).size()
#define mp make_pair
#define sqr(s) ((s) * (s))
 
using namespace std;
 
typedef complex<int> point;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

int ans[305][305];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> ans[i][j];
    }*/
    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j < n / 2)
                    ans[i][j] = i * n / 2 + j + 1;
                else
                    ans[i][j] = n * n / 2 + (n - i) * n / 2 - (n - j - 1);
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != n / 2) {
                    if (j < n / 2)
                        ans[i][j] = i * n + j + 1;
                    else if (j == n / 2)
                        ans[i][j] = n * n / 2 + n / 2 - i + 1;
                    else
                        ans[i][j] = (n - i) * n - (n - j - 1);
                } else {
                    ans[i][j] = n / 2 + n * j + 1;
                }
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    /*int res = n * n + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            cout << i << " " << j << endl;
            int cnt = 0;
            for (int a = 0; a < n; a++) {
                for (int b = 0; b < n; b++) {
                    if (ans[i][a] > ans[j][b])
                        cnt++;
                }
            }
            cout << cnt << endl;
            res = min(res, cnt);
        }
    }
    cout << res << endl;
    //assert(res == n * n / 2);*/
}
