#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int n, m, i, j, u, v, c;
int q[maxN * 10], h, t;
set <int> s1, s2;
vector <int> G[maxN], res, cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (i = 0; i < m; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (i = 1; i <= n; i++){
        s1.insert(i);
    }
    while (!s1.empty()){
        h = 0, t = 0;
        q[t] = *(s1.begin());
        s1.erase(q[t++]);
        cnt.push_back(0);
        while (h < t){
            v = q[h++];
            res.push_back(v);
            cnt[cnt.size() - 1] += 1;
            s2 = s1;
            for (auto u : G[v]){
                s2.erase(u);
            }
            for (auto u : s2){
                q[t++] = u;
                s1.erase(u);
            }
        }
    }
    cout << cnt.size() - 1 << endl;
	return 0;
}
