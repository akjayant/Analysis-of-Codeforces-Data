#include <bits/stdc++.h>

using namespace std;

#define long long long int 

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector <vector<int>> ans(n, vector<int>(n));

    int cur = 1;

    for (int j = 0; j < n; ++j) {
        if (j % 2 == 0) {
            for (int i = n - 1; i > -1; --i)
                ans[i][j] = cur++;
        }
        else {
            for (int i = 0; i < n; ++i)
                ans[i][j] = cur++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
   
    return 0;
}