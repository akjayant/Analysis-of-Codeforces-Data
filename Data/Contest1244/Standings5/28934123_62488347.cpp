#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, i, j;
    cin >> n;
    int c[3][n];
    vector<int> yh[n];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    for (i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        yh[u].push_back(v);
        yh[v].push_back(u);
    }
    int r[n];
    for (i = 0; i < n; i++) {
        if (yh[i].size() == 1) {
            r[0] = i;
            r[1] = yh[i][0];
            break;
        }
    }
    for (i = 1; i < n - 1; i++) {
        if (yh[r[i]].size() != 2) {
            cout << -1;
            return 0;
        }
        if (yh[r[i]][0] == r[i - 1]) {
            r[i + 1] = yh[r[i]][1];
        }
        else {
            r[i + 1] = yh[r[i]][0];
        }
    }
    int vm[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    long long mn = -1;
    int mi;
    for (i = 0; i < 6; i++) {
        long long s = 0;
        for (j = 0; j < n; j++) {
            s += c[vm[i][j % 3]][r[j]];
        }
        if (mn == -1 || mn > s) {
            mn = s;
            mi = i;
        }
    }
    int fc[n];
    for (i = 0; i < n; i++) {
        fc[r[i]] = vm[mi][i % 3] + 1;
    }
    cout << mn << endl;
    for (i = 0; i < n; i++) {
        cout << fc[i] << " ";
    }
}
