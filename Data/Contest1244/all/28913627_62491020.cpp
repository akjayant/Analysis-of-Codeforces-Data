#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3e5 + 7;

int n, c1[N], c2[N], c3[N], st[N];
vector<int> g[N], v;

void dfs(int cur, int p) {
    v.push_back(cur);
    for(int i=0;i<g[cur].size();i++) {
        int to = g[cur][i];
        if(to != p)
            dfs(to, cur);
    }
}
ll ans = -1, a1, a2, a3, col[N];
void try_colors(vector<int> cl) {
    int turn = 0;
    ll curans = 0;
    for(int i=0;i<v.size();i++) {
        int cr = cl[turn];
        if(cr == 1)
            curans += c1[v[i]];
        if(cr == 2)
            curans += c2[v[i]];
        if(cr == 3)
            curans += c3[v[i]];
        turn++;
        if(turn == 3)
            turn = 0;
    }
    if(curans < ans || ans == -1) {
        ans = curans;
        a1 = cl[0];
        a2 = cl[1];
        a3 = cl[2];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>c1[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>c2[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>c3[i];
    }
    for(int i=1;i<n;i++) {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        st[x]++;
        st[y]++;
    }
    int first = -1;
    for(int i=1;i<=n;i++) {
        if(st[i] == 1)
            first = i;
        if(st[i] > 2) {
            cout<<-1;
            return 0;
        }
    }
    dfs(first, -1);
    try_colors({1, 2, 3});
    try_colors({1, 3, 2});
    try_colors({2, 1, 3});
    try_colors({2, 3, 1});
    try_colors({3, 2, 1});
    try_colors({3, 1, 2});
    cout<<ans<<endl;
    int turn = 0;
    for(int i=0;i<v.size();i++) {
        if(turn == 0)
            col[v[i]] = a1;
        if(turn == 1)
            col[v[i]] = a2;
        if(turn == 2)
            col[v[i]] = a3;
        turn++;
        if(turn == 3)
            turn = 0;
    }
    for(int i=1;i<=n;i++)
        cout<<col[i]<<" ";
}
