#include <bits/stdc++.h>
using namespace std;
typedef long long llint;
const llint MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<vector<llint>> c(3, vector<llint>(N));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < N; j++) {
            cin >> c[i][j];
        }
    }
    vector<vector<int>> vv(N);
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        vv[--u].push_back(--v);
        vv[v].push_back(u);
    }
    llint ans = 1e18;
    vector<int> mincolors(N, -1);
    bool moze = true;
    int a = 0, b = vv[0][0];
    for(int i = 0; i < N; i++) {
        if(vv[i].size() > 2) {
            moze = false;
        }
        if(vv[i].size() == 1) {
            a = i;
            b = vv[i][0];
        }
    }
    if(!moze) {
        cout << -1;
        return 0;
    }
    for(int ca = 0; ca < 3; ca++) {
        for(int cb = 0; cb < 3; cb++) {
            if(ca == cb)
                continue;
            vector<int> colors(N, -1);
            colors[a] = ca;
            colors[b] = cb;
            int A = a, B = b;
            llint trosak = c[ca][a] + c[cb][b];
            for(int i = 0; i < N - 2; i++) {
                for(auto e: vv[B]) {
                    if(colors[e] == -1) {
                        colors[e] = 3 - colors[A] - colors[B];
                        trosak += c[colors[e]][e];
                        A = B;
                        B = e;
                        break;
                    }
                }
            }
            if(trosak < ans) {
                ans = trosak;
                mincolors = colors;
            }
        }
    }
    cout << ans << endl;
    for(auto e: mincolors)
        cout << e + 1 << " ";
}