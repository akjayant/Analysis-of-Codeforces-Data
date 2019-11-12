#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Pair {
    int i, j;
};

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
//    cerr << n << s << t << endl;

    vector<Pair> res;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
//            cerr << "i = " << i << endl;
            bool done = false;
            for (int j = i + 1; j < n; j++) {
                if (s[j] != t[j] && s[j] == s[i]) {
                    swap(s[j], t[i]);
                    res.push_back({j, i});
                    done = true;
                    break;
                }
            }
            if (!done) {
                for (int j = i + 1; j < n; j++) {
                    if (s[j] != t[j] && t[j] == s[i]) {
                        res.push_back({j, j});
                        swap(s[j], t[j]);
                        res.push_back({j, i});
                        swap(s[j], t[i]);
                        done = true;
                        break;
                    }
                }
            }
            if (!done) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl << res.size() << endl;
    for (Pair p : res) {
        cout << p.i + 1 << " " << p.j + 1 << endl;
    }
}

int main() {
    int k;
    cin >> k;
//    cerr << k << endl;
    for (int i = 0; i < k; i++) {
        solve();
    }
    return 0;
}
