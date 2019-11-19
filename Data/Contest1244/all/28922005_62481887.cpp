#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>

typedef long long LL;
using namespace std;
vector<vector<int> > g;
vector<vector<int>> c;

vector<int> ansColors;
LL ansSum = 1e18;
vector<int> colors;
LL ans;

int otherColor(int c1, int c2) {
    return 3 - c1 - c2;
}

void rec(int v, int p_v, int col) {
    colors[v] = col;
    ans += c[col][v];
    for(int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if(colors[to] == -1) {
            rec(to, v, otherColor(colors[v], colors[p_v]));
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    g.resize(n);
    colors.resize(n, -1);
    c.resize(3, vector<int>(n));
    for(int j = 0; j < 3; ++j) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &c[j][i]);
        }
    }
    for(int i = 1; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i =0 ; i < n; ++i) {
        if(g[i].size() >= 3) {
            cout << -1;
            return 0;
        }
    }

    //find leaf
    int leaf, n_leaf;
    for(int i = 0; i < n; ++i) {
        if(g[i].size() == 1) {
            leaf = i;
            n_leaf = g[i][0];
            break;
        }
    }

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(i == j) {
                continue;
            }
            colors.assign(n, -1);
            colors[leaf] = i;
            ans = c[i][leaf];
            rec(n_leaf, leaf, j);

            if(ans < ansSum) {
                ansSum = ans;
                ansColors = colors;
            }
        }
    }

    if(ansSum == 1e18) {
        cout << -1;
    } else {
        cout << ansSum << "\n";
        for(int i =0 ; i < n; ++i) {
            cout << ansColors[i] + 1 << " ";
        }
    }
}