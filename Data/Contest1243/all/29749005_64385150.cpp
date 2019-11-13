#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e5 + 15;

int _, n;
string s, t;

int main() {
    cin >> _;
    while (_--) {
        cin >> n >> s >> t;
        pair<char, char> p = {'0', '0'};
        bool flag = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if(s[i] != t[i]){
                ++cnt;
            }
            if (s[i] != t[i] && p.first == '0') {
                p = {s[i], t[i]};
            } else if (s[i] != t[i]) {
                flag = s[i] == p.first && t[i] == p.second;
            }
        }
        if (flag && cnt == 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

