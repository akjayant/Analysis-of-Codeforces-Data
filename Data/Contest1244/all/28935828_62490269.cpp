#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll c[4][maxn];
vector<int> G[maxn];
int d[maxn];
//        ll ans1 = dfs(st, 0, 1, 0); // 1 2 3
//        ll ans2 = dfs(st, 0, 2, 0); // 1 3 2
//        ll ans3 = dfs(st, 0, 3, 0); // 2 1 3
//        ll ans4 = dfs(st, 0, 4, 0); // 2 3 1
//        ll ans5 = dfs(st, 0, 5, 0); // 3 1 2
//        ll ans6 = dfs(st, 0, 6, 0); // 3 2 1

int color[6][maxn];
ll dfs(int u, int fa, int kind, int v)
{
    ll ans = 0;
    if(kind == 1){
        if(v == 0) ans += c[1][u], color[0][u] = 1;
        else if(v == 1) ans += c[2][u], color[0][u] = 2;
        else if(v == 2) ans += c[3][u], color[0][u] = 3;
    }
    else if(kind == 2){
        if(v == 0) ans += c[1][u], color[1][u] = 1;
        else if(v == 1) ans += c[3][u], color[1][u] = 3;
        else if(v == 2) ans += c[2][u], color[1][u] = 2;
    }
    else if(kind == 3){
        if(v == 0) ans += c[2][u], color[2][u] = 2;
        else if(v == 1) ans += c[1][u], color[2][u] = 1;
        else if(v == 2) ans += c[3][u], color[2][u] = 3;
    }
    else if(kind == 4){
        if(v == 0) ans += c[2][u], color[3][u] = 2;
        else if(v == 1) ans += c[3][u], color[3][u] = 3;
        else if(v == 2) ans += c[1][u], color[3][u] = 1;
    }
    else if(kind == 5){
        if(v == 0) ans += c[3][u], color[4][u] = 3;
        else if(v == 1) ans += c[1][u], color[4][u] = 1;
        else if(v == 2) ans += c[2][u], color[4][u] = 2;
    }
    else if(kind == 6){
        if(v == 0) ans += c[3][u], color[5][u] = 3;
        else if(v == 1) ans += c[2][u], color[5][u] = 2;
        else if(v == 2) ans += c[1][u], color[5][u] = 1;
    }
    for(auto vv : G[u]){
        if(vv == fa) continue;
        ans += dfs(vv, u, kind, (v + 1) % 3);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }
    bool f = true;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        d[u]++;
        d[v]++;
    }
    int cnt1 = 0;
    int cnt2 = 0;
    int st;
    for(int i = 1; i <= n; i++){
        if(d[i] > 2) {
            f = false;
            break;
        }
        else if(d[i] == 1){
            cnt1++;
            st = i;
        }
        else if(d[i] == 2){
            cnt2++;
        }
    }
    if(f && cnt1 == 2 && cnt2 == n - 2){
        pair<ll, ll> ans[10];
        for(int i = 0; i < 6; i++){
            ans[i].second = i;
        }
        ans[0].first = dfs(st, 0, 1, 0); // 1 2 3
        ans[1].first = dfs(st, 0, 2, 0); // 1 3 2
        ans[2].first = dfs(st, 0, 3, 0); // 2 1 3
        ans[3].first = dfs(st, 0, 4, 0); // 2 3 1
        ans[4].first = dfs(st, 0, 5, 0); // 3 1 2
        ans[5].first = dfs(st, 0, 6, 0); // 3 2 1
        sort(ans, ans + 6);
        cout << ans[0].first << endl;
        for(int i = 1; i <= n; i++){
            cout << color[ans[0].second][i] << " ";
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }

}
