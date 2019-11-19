#include <bits/stdc++.h>

using namespace std;

long long n, f, f1;
vector<vector<long long> > g(2e5, vector<long long>());
vector<long long> v;
vector<long long> temp;
vector<long long> arr;
long long c1[200000];
long long c2[200000];
long long c3[200000];
long long color1[200000];
long long val[200000];
long long val1[200000];
long long color2[200000];
long long color3[200000];
void dfs(int ver, int p) {
    for (int i = 0; i < g[ver].size(); i++) {
        int to = g[ver][i];
        if (to != p) {
            v.push_back(to);
            dfs(to, ver);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c1[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c2[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c3[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> f >> f1;
        g[f].push_back(f1);
        g[f1].push_back(f);
    }
    long long fir = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() != 1 && g[i].size() != 2) {
            cout << -1;
            return 0;
        }
        if (g[i].size() == 1) {
            fir = i;
        }
    }
    v.push_back(-1);
    v.push_back(fir);
    dfs(fir, -1);
    for (int i = 1; i <= n; i++) {
        color1[i] = c1[v[i]] + color1[i - 3];
        color2[i] = c2[v[i]] + color2[i - 3];
        color3[i] = c3[v[i]] + color3[i - 3];
    }
    temp.push_back(n - 2);
    temp.push_back(n - 1);
    temp.push_back(n);
    long long mi = 1e18;
    do {
        if (color1[temp[0]] + color2[temp[1]] + color3[temp[2]] < mi) {
            mi = color1[temp[0]] + color2[temp[1]] + color3[temp[2]];
            arr = temp;
        }
    } while (next_permutation(temp.begin(), temp.end()));
    long long pos = arr[0];
    while (pos > 0) {
        val[pos] = 1;
        pos -= 3;
    }
    pos = arr[1];
    while (pos > 0) {
        val[pos] = 2;
        pos -= 3;
    }
    pos = arr[2];
    while (pos > 0) {
        val[pos] = 3;
        pos -= 3;
    }
    for (int i = 1; i <= n; i++) {
        val1[v[i]] = val[i];
    }
    cout << mi << endl;
    for (int i = 1; i <= n; i++) {
        cout << val1[i] << " ";
    }
}
