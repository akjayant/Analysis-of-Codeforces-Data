#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, n;
string s;
const long long maxn = 1000000007;
vector<long long> fib;
vector<char> str;
vector<int> amount;
map<char, int> ind;
map<int, char> anti_ind;

int main() {
    cin >> t;
    amount.resize(3);
    ind['R'] = 0;
    ind['S'] = 2;
    ind['P'] = 1;
    anti_ind[0] = 'R';
    anti_ind[1] = 'P';
    anti_ind[2] = 'S';
    str.push_back('R');
    str.push_back('P');
    str.push_back('S');
    for (int h = 0; h < t; h++) {
        cin >> n >> amount[0] >> amount[1] >> amount[2];
        cin >> s;
        int wins = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (amount[(ind[s[i]] + 1) % 3] > 0) {
                wins++;
                --amount[(ind[s[i]] + 1) % 3];
                ans += anti_ind[(ind[s[i]] + 1) % 3];
            } else {
                ans += ".";
            }
        }
        if (n % 2 == 1) {
            if (wins > n / 2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
                continue;
            }
        } else {
            if (wins >= n / 2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
                continue;
            }
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == '.') {
                for (int j = 0; j < 3; j++) {
                    if (amount[j] != 0) {
                        amount[j]--;
                        ans[i] = anti_ind[j];
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}