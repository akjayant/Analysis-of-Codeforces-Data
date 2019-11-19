//
// Created by 93569 on 2019/10/13.
//
#include<bits/stdc++.h>

#define LL long long
using namespace std;
//
// Created by 93569 on 2019/10/13.
//
int n;
long long p[4][100000 + 200];
int du[100000 + 200];
vector<int> e[100000 + 100];

int A[10][100000 + 200];
long long Cost[10];

void dfs(int ty, int a, int b, int x, int y) {
    if (e[b].size() == 1) return;
    int c = (e[b][0] == a) ? e[b][1] : e[b][0];
    for (int i = 0; i < 3; i++) {
        if (i == x || i == y) continue;
        A[ty][c] = i;
        Cost[ty] += p[i][c];
        dfs(ty, b, c, y, i);
        break;
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[0][i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[1][i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[2][i];
    }
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        du[a]++;
        du[b]++;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int tot = 0;
    int s;
    for (int i = 1; i <= n; i++) {
        if (du[i] >= 3) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (du[i] == 1) {
            s=i;
            break;
        }
    }
    int st = s, tt = e[st][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            Cost[i * 3 + j] = p[i][st] + p[j][tt];
            A[i*3+j][st]=i;
            A[i*3+j][tt]=j;
            dfs(i * 3 + j, st, tt, i, j);
        }
    }
    int tttt = 0;
    long long ans = 999999999999999;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            if (ans > Cost[i * 3 + j]) {
                ans = Cost[i * 3 + j];
                tttt = i * 3 + j;
            }
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) {
        cout << A[tttt][i] + 1 << " ";
    }

    return 0;
}
