#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int sz = 1e5 + 100;
const ll mod = 1e9 + 7;

int n, m;
set <int> st;
set <int> G[sz];
int ar[sz];
int fl[sz];
int c;

void bfs(int u) {
    queue<int> q;
    q.push(u);
    vector <int> er;
    while (q.empty() == false) {
        u = q.front();
        q.pop();
        er.clear();
        fl[u] = c;
        for (int v: st) {
            if (G[u].find(v) == G[u].end()) {
                q.push(v);
                er.push_back(v);
            }
        }
        for (int v: er) {
            st.erase(v);
        }
    }
}

int main() {

    while (cin >> n >> m) {

        memset(ar, 0, sizeof ar);

        memset(fl, 0, sizeof fl);

        for (int i = 1; i <=n; i++) {
            G[i].clear();
        }

        while (m--) {
            int x, y;
            cin >> x >> y;
            G[x].insert(y);
            G[y].insert(x);
            ar[x]++;
            ar[y]++;
        }

        st.clear();

        for (int i = 1; i <=n; i++) {
            if (ar[i] < n - 1) {
                st.insert(i);
            }
        }

        while (st.empty() == false) {
            int u = *st.begin();
            st.erase(u);
            c++;
            bfs(u);
        }

        set <int> ans;

        for (int i = 1; i <= n; i++) {
            if (!fl[i]) fl[i] = ++c;
            ans.insert(fl[i]);
        }

        cout << ((int)ans.size()) - 1 << "\n";

        cerr << "-----\n";
    }

    return 0;
}