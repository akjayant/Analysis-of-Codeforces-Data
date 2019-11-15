#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define ld long double
#define ll long long
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define endl '\n'

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 3e5 + 10;
const ll MOD = 1e9 + 7;
const int rx[4] = {-1, 0, 1, 0};
const int ry[4] = {0, 1, 0, -1};
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int hx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int hy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const ld eps = 1e-7;
const double pi = acos(-1.0);
const int INF = 2e9;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        int za = a, zb = b, zc = c;
        string s;
        cin >> s;
        int ans = 0;
        string t;
        for (int i = 0; i < n; i++) {
            t += "#";
            char ch = s[i];
            if (ch == 'R' && b) {
                b --;
                ans ++;
                t[i] = 'P';
            } else if (ch == 'P' && c) {
                c --;
                ans ++;
                t[i] = 'S';
            } else if (ch == 'S' && a) {
                a --;
                ans ++;
                t[i] = 'R';
            }
        }
        if (ans >= (n + 1) / 2) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                if (t[i] == '#') {
                    if (a) {
                        t[i] = 'R';
                        a --;
                    } else if (b) {
                        t[i] = 'P';
                        b --;
                    } else {
                        t[i] = 'S';
                        c --;
                    }
                }
            }
            cout << t << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}

