
#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = int64_t;



int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n; cin >> n;
    vector<array<int,3>> cost(n);
    rep(i,n) cin >> cost[i][0];
    rep(i,n) cin >> cost[i][1];
    rep(i,n) cin >> cost[i][2];

    Graph g(n);
    rep(i,n-1) {
        int a,b; cin >>a>>b; --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int leaf = -1;
    rep(i,n) {
        if(g[i].size()>2) {
            cout << -1 << endl;
            return 0;
        } else  if(g[i].size()==1) {
            leaf = i;
        }
    }

    vector<int> path;
    int last = -1;
    int cur = leaf;
    while(true){
        path.push_back(cur);
        int next = -1;
        for(int nei : g[cur])
            if(nei != last) next = nei;
        if(next == -1) break;
        last  = cur;
        cur = next;
    }

    ll best = 1e15;
    string bestSeq;
    vector<string> seqs{ "012", "021", "102", "120", "201", "210" };
    for(auto seq : seqs) {
        ll total = 0;
        rep(i,n) total += cost[path[i]][seq[i%3]-'0'];
        if(total < best) {
            best = total;
            bestSeq = seq;
        }
    }

    cout << best << endl;
    vector<int> cols(n);
    rep(i,n) cols[path[i]] = bestSeq[i%3]-'0';
    rep(i,n) cout << cols[i] + 1 << ' ';
    cout << endl;



    return 0;
}

