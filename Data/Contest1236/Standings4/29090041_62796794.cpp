#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<vector<int>> mat(n + 1, vector<int>(n + 1));

    int cnt = 1;
    for (int j = 1; j <= n; j++)
        if (j % 2)
            for (int i = 1; i <= n; i++)
                mat[i][j] = cnt++;
        else
            for (int i = n; i >= 1; i--)
                mat[i][j] = cnt++;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << mat[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
