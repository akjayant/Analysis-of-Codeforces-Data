#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxN = 1e5+10;
LL cost[3][maxN];
vector<int> edge[maxN];
LL Ans[maxN];
bool visit[maxN];
vector<int> seq;
vector<pair<int, int> > tt;
LL dfs(int s) {
    visit[s] = true;
    seq.push_back(s);
    for(int i = 0; i < edge[s].size(); i++) {
        int to = edge[s][i];
        if(!visit[to]) {
            LL tmp = dfs(to);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> cost[0][i];       
    }
    for(int i = 0; i < n; i++) {
        cin >> cost[1][i];       
    }
    for(int i = 0; i < n; i++) {
        cin >> cost[2][i];       
    }
    int u, v;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;       
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int start = -1;
    for(int i = 1; i <= n; i++) {
        if(edge[i].size() >= 3) {
            cout << -1 << endl;
            return 0;
        }
        if(edge[i].size() == 1) start = i;
    }
    if(start == -1) {
        cout << -1 << endl;
        return 0;
    }

    //cout << "in finish " << endl;
    dfs(start);
    //cout << "after dfs " << endl;
    LL ans = 1000000LL*1000000LL*100000LL;
    int fu, fv;
    for(int u = 0; u < 3; u++) {
        for(int v = 0; v < 3; v++) {
            if(u==v) continue;
            Ans[0] = u; Ans[1] = v;
            LL tmp = cost[u][seq[0]-1] + cost[v][seq[1]-1];
            for(int i = 2; i < n; i++) {
                Ans[i] = 3-Ans[i-1]-Ans[i-2];
                tmp += cost[Ans[i]][seq[i]-1];
            }
            if(ans > tmp) {
                ans = tmp;
                fu = u; fv = v;
            }
        }
    } 
    cout << ans << endl;
    fu++; fv++;
    //cout << fu << " " << fv << " ";
    Ans[0] = fu; Ans[1] = fv;
    tt.push_back(make_pair(seq[0], fu));
    tt.push_back(make_pair(seq[1], fv));
    for(int i = 2; i < n; i++) {
        Ans[i] = 6 - Ans[i-1] - Ans[i-2]; 
        //cout << Ans[i] << " ";
        tt.push_back(make_pair(seq[i], Ans[i]));
    }
    sort(tt.begin(), tt.end());
    for(int i = 0; i < n; i++) {
        cout << tt[i].second << " ";
    }
    cout << endl;
    return 0;
}
