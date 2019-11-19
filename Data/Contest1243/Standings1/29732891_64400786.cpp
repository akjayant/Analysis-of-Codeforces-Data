#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvvi> vvvvi;
typedef tuple<int, int, int> iii;
typedef vector<iii> viii;

set<int> st;
map<ii, int> M;
vi vis;

void dfs(int v, int col) {
    vis[v] = col;
    vi aux;
    for (auto to : st) {
        if (M.find({min(v, to), max(v, to)}) == M.end()) aux.push_back(to);
    }
    for (int i = 0; i < aux.size(); ++i) st.erase(aux[i]);
    for (int i = 0; i < aux.size(); ++i) {
        if (!vis[aux[i]]) dfs(aux[i], col);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vi A(m), B(m), weight(m);
    vis = vi(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        A[i] = a-1, B[i] = b-1, weight[i] = 1;
        M[{A[i], B[i]}] = 1;
    }

    for (int i = 0; i < n; ++i) st.insert(i);
    int col = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            st.erase(i);
            col++;
            dfs(i, col);
        }
    }
    cout << col - 1 << "\n";
    return 0;
}