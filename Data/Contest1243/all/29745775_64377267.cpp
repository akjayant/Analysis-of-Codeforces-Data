#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long long;

int main() {
    ios_base::sync_with_stdio(0);
    int k;
    cin >> k;
    for (int test = 0; test < k; test++) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<int> g;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                g.push_back(i);
            }
        }
        if (g.size() == 2) {
            swap(a[g[0]], b[g[1]]);
            if (a == b) {
                cout << "Yes\n";
            } else {
                swap(a[g[0]], b[g[1]]);
                swap(a[g[1]], b[g[0]]);
                if (a == b) {
                    cout << "Yes\n";
                } else {
                    cout << "No\n";
                }
            }
        } else {
            cout << "No\n";
        }
    }
}
