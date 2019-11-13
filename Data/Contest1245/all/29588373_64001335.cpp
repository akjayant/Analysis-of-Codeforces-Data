#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAXN = 101;
int arr[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int j = 0; j < t; ++j) {
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        vector<char> ans(n);
        int v = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'P' && c > 0) {
                ++v;
                ans[i] = 'S';
                --c;
            }
            if (s[i] == 'R' && b > 0) {
                ++v;
                ans[i] = 'P';
                --b;
            }
            if (s[i] == 'S' && a > 0) {
                ++v;
                ans[i] = 'R';
                --a;
            }
        }
        if (v >= (n + 1) / 2) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                if (ans[i] == 'R' || ans[i] == 'S' || ans[i] == 'P') {
                    cout << ans[i];
                } else {
                    if (a > 0) {
                        cout << 'R';
                        --a;
                    } else if (b > 0) {
                        cout << 'P';
                        --b;
                    } else if (c > 0) {
                        cout << 'S';
                        --c;
                    }
                }
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
