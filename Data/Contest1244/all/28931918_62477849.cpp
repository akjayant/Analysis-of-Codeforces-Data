#include <iostream>
#include <vector>

using namespace std;

vector < vector<int> > edges;
vector<int> bb;
vector<int> used;

void do_part(int u, int flg) {
    used[u] = 1;
    if (flg)
        bb.push_back(u);
    for (auto &v: edges[u]) {
        if (used[v])
            continue;
        do_part(v, flg);
    }
    if (!flg)
        bb.push_back(u);
}

void do_bamboo(int u, int v) {
    used[u] = 1;
    used[v] = 1;
    do_part(u, 0);
    do_part(v, 1);
}


int main() {
    int n;
    scanf("%d", &n);
    vector<int> c[3];
    for (int i = 0; i < 3; ++i) {
        c[i].resize(n);
        for (int j = 0; j < n; ++j)
            scanf("%d", &c[i][j]);
    }

    edges.resize(n);
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &u, &v);
        u--; v--;
        if (edges[u].size() >= 2 || edges[v].size() >= 2) {
            cout << -1 << endl;
            return 0;
        }
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    used.resize(n, 0);
    do_bamboo(u, v);

    int c1, c2;
    long long bstnum = 1e18, curnum;
    vector<int> bst(n), cur(n);
    for (c1 = 0; c1 < 3; ++c1) {
        for (c2 = 0; c2 < 3; ++c2) {
            if (c1 == c2)
                continue;
            curnum = c[c1][bb[0]] + c[c2][bb[1]];
            cur[0] = c1; cur[1] = c2;
            for (int i = 2; i < n; ++i) {
                cur[i] = 3 - cur[i - 1] - cur[i - 2];
                curnum += c[cur[i]][bb[i]];
            }
            if (curnum < bstnum) {
                bstnum = curnum;
                swap(bst, cur);
            }
        }
    }
    cout << bstnum << endl;
    for (int i = 0; i < n; ++i)
        cur[bb[i]] = bst[i];
    for (auto &vv: cur)
        cout << vv + 1 << " ";
    cout << endl;
}
