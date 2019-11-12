#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            cout << n * (j - 1) + ((j & 1) ? i : n - i + 1) << (j == n ? '\n' : ' ');
        }
    }
}