#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 5;
vector<int> g[N];
ll c[3][N];
ll ans = 1e18;
int nxt[3];
vector < pair < int , int >  > t, a;
ll dfs(int node, int parent, int color) {
    t.push_back({node, color});
    ll ret = 0;
    for (auto child : g[node]) {
        if (child != parent) {
            ret += dfs(child, node, nxt[color]);
        }
    }
    return ret + c[color][node];
}
void check(ll temp){
    if (temp < ans){
        a = t;
        ans = temp;
    }
    t.clear();
}
int color[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int root = 1;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() > 2)
            return cout << -1, 0;
        if (g[i].size() == 1)
            root = i;
    }
    ll temp;
    nxt[0] = 1, nxt[1] = 2, nxt[2] = 0;
    temp = dfs(root, -1, 0);
    check(temp);
    temp = dfs(root, -1, 1);
    check(temp);
    temp = dfs(root, -1, 2);
    check(temp);
    nxt[0] = 2, nxt[1] = 0, nxt[2] = 1;
    temp = dfs(root, -1, 0);
    check(temp);
    temp = dfs(root, -1, 1);
    check(temp);
    temp = dfs(root, -1, 2);
    check(temp);
    for(auto it : a){
        color[it.first] = it.second;
    }
    cout << ans <<"\n";
    for(int i =1 ; i <= n ; i++)
        cout << color[i] + 1 <<' ' ;
    return 0;
}