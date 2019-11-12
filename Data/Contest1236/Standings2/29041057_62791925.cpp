#include <bits/stdc++.h>

using namespace std;

using ll =  long long;
using Pll = pair<ll, ll>;
using Pii = pair<int, int>;

constexpr ll MOD = 1000000007;
constexpr long double EPS = 1e-10;
constexpr int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    int m = 1;
    for(int i=0;i<n;++i) {
        if(i%2) {
            for(int j=n-1;j>=0;--j) a[j].push_back(m++);
        } else {
            for(int j=0;j<n;++j) a[j].push_back(m++);
        }
    }

    for(int i=0;i<n;++i) {
        cout << a[i][0];
        for(int j=1;j<n;++j) cout << " " << a[i][j];
        cout << endl;
    }
}
