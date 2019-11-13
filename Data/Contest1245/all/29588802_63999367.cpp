#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define sync ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
#define fr(x, n) for (int x = 0; x < n; x++)
#define int long long
#define pb push_back
#define y1 fadasdsadassa
#define random mt19937 rng(time(nullptr));

using namespace std;

const double eps = 1e-9;
const double EPS = 1e-17; 
const int M = 1e5 + 1;
const int INF = 1e17 + 7;
const int MOD = 1e9 + 7;
const int inf = 1e9 + 7;
const int N = 1e5 + 1;

int n, m;
vector <int> v;

signed main () { sync;
    int t;
    cin >> t;
    while (t--) {
        int n;
        int a, b, c;
        cin >> n;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        string ans;
        int win = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                if (b) {
                    ans.push_back('P');
                    b--;
                    win++;
                }
                else {
                    ans.push_back('?');
                }
            }
            else if (s[i] == 'P') {
                if (c) {
                    ans.push_back('S');
                    c--;
                    win++;
                }
                else {
                    ans.push_back('?');
                }
            }
            else {
                if (a) {
                    ans.push_back('R');
                    a--;
                    win++;
                }
                else {
                    ans.push_back('?');
                }
            }
        }
        if (win >= (n + 1) / 2) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (ans[i] == '?') {
                    if (a) {
                        ans[i] = 'R';
                        a--;
                    }
                    else if (b) {
                        ans[i] = 'P';
                        b--;
                    }
                    else if (c) {
                        ans[i] = 'S';
                        c--;
                    }
                } 
            }
            cout << ans << '\n';
        }
        else {
            cout << "NO\n";
        }
    }
}
