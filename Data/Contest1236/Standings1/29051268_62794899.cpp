#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define F(i, n) for(int i = 0; i < n; ++ i)

int32_t main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int> > v(n, vector<int>(n));
    int cur = 1;
    F(j, n) F(i, n) {
        if(j % 2 == 0) {
            v[i][j] = cur++;
        } else {
            v[n - i - 1][j] = cur++;
        }
    }

    F(i, n) {
        F(j, n) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}
