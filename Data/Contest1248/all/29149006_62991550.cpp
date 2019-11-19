#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

#define ff first
#define ss second

const double eps = 1e-6;
const int mod = 45;
const int maxn = 1e5 + 7;

vector<vector<int>> g, gr;
vector<bool> used;
vector<int> ord, comp;

void ts(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            ts(to);
        }
    }
    ord.push_back(v);
}

void dfs(int v) {
    used[v] = true;
    comp.push_back(v);
    for (int to : gr[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}

int main() {
#ifdef JOPA
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        g.assign(n, vector<int>());
        gr.assign(n, vector<int>());
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].push_back(b);
            gr[b].push_back(a);
        }

        used.assign(n, false);
        ord.clear();
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                ts(i);
            }
        }

        reverse(ord.begin(), ord.end());
        used.assign(n, false);
        vector<int> ans;
        vector<int> clr(n, -1);
        for (int i : ord) {
            if (!used[i]) {
                comp.clear();
                dfs(i);
                bool flag = true;
                if (comp.size() == n) {
                    flag = false;
                }

                for (int j : comp) {
                    clr[j] = i;
                }

                for (int j : comp) {
                    if (!flag) break;
                    for (int k : gr[j]) {
                        if (clr[k] != i) {
                            flag = false;
                        }
                    }
                }
                if (comp.size() != n) {
                    ans = comp;
                }
            }
        }
        if (ans.size() == 0) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            cout << comp.size() << " " << n - comp.size() << "\n";
            vector<bool> cat(n, true);
            for (int i : ans) {
                cout << i + 1 << " ";
                cat[i] = false;
            }
            cout << "\n";
            for (int i = 0; i < n; i++) {
                if (cat[i]) {
                    cout << i + 1 << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
