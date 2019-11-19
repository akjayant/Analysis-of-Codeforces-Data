#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        long long p[2] = {};
        for(int i=0; i<n; ++i) {
            int a; cin >> a;
            p[abs(a) % 2] += 1;
        }

        int m; cin >> m;
        long long q[2] = {};
        for(int i=0; i<m; ++i) {
            int a; cin >> a;
            q[abs(a) % 2] += 1;
        }

        cout << p[0] * q[0] + p[1] * q[1] << '\n';
    }
}