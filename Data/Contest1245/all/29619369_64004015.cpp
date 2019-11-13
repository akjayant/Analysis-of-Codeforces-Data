#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvvi> vvvvi;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        vi alice(3), bob(3);
        int n;
        string s;
        cin >> n;
        for (int i = 0; i < 3; ++i) cin >> alice[i];
        cin >> s;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') bob[0]++;
            else if (s[i] == 'P') bob[1]++;
            else bob[2]++;
        }
        int a = min(alice[0], bob[2]);
        int b = min(alice[1], bob[0]);
        int c = min(alice[2], bob[1]);
        if (a + b + c >= (n+1)/2) {
            cout << "YES\n";
            string ans(n, 'a');
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'R' && b) {
                    ans[i] = 'P';
                    b--;
                    alice[1]--;
                } else if (s[i] == 'P' && c) {
                    ans[i] = 'S';
                    c--;
                    alice[2]--;
                } else if (s[i] == 'S' && a) {
                    ans[i] = 'R';
                    a--;
                    alice[0]--;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (ans[i] == 'a') {
                    if (alice[0]) {
                        alice[0]--;
                        ans[i] = 'R';
                    } else if (alice[1]) {
                        alice[1]--;
                        ans[i] = 'P';
                    } else {
                        alice[2]--;
                        ans[i] = 'S';
                    }
                }
            }
            cout << ans << "\n";
        } else cout << "NO\n";
    }
    return 0;
}