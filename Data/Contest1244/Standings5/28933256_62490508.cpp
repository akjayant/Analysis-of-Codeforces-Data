#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <list>
#include <map>
#include <istream>
#include <bitset>
#include <sstream>
#include <unordered_map>
#include <stack>
#include <set>
#include <cmath>
#include <random>
#include <iostream>
#include <bitset>
#include <iomanip>
#include <queue>
#include <string>

#define int long long
#define endl "\n"
#define all(x) x.begin(),x.end()
#define rr return 0
#define xx first
#define yy second
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
vector<vector<int>> c;
vector<vector<int>> g;
vector<int> t;
//vector<vector<int>> dp;
//vector<vector<pii>> son;
//
//void dfs(int v, int pr = -1){
//    for(auto i : g[v]){
//        if(i != pr)
//            dfs(i, v);
//    }
//    if(g[v].size() == 1 && v != 1){
//        dp[v][1] = min(c2[v], c3[v]);
//        dp[v][2] = min(c1[v], c3[v]);
//        dp[v][3] = min(c1[v], c2[v]);
//    }else if(g[v].size() == 2){
//        int s;
//        if(g[v][0] == pr){
//            s = g[v][1];
//        }else{
//            s = g[v][0];
//        }
//        if(dp[s][2] + c3[v] < dp[s][3] + c2[v]){
//            dp[v][1] = dp[s][2] + c3[v];
//            son[v][1] = {3, 2};
//        }else{
//            dp[v][1] = dp[s][3] + c2[v];
//            son[v][1] = {2, 3};
//        }
//        if(dp[s][1] + c3[v] < dp[s][3] + c1[v]){
//            dp[v][2] = dp[s][1] + c3[v];
//            son[v][2] = {3, 1};
//        }else{
//            dp[v][2] = dp[s][3] + c1[v];
//            son[v][2] = {1, 3};
//        }
//        if(dp[s][1] + c2[v] < dp[s][2] + c1[v]){
//            dp[v][3] = dp[s][1] + c2[v];
//            son[v][3] = {2, 1};
//        }else{
//            dp[v][3] = dp[s][2] + c1[v];
//            son[v][3] = {1, 2};
//        }
//    }else if(v == 1){
//        int s = g[v][0];
//        if(dp[s][2] + c3[v] < dp[s][3] + c2[v]){
//            dp[v][1] = dp[s][2] + c3[v];
//            son[v][1] = {3, 2};
//        }else{
//            dp[v][1] = dp[s][3] + c2[v];
//            son[v][1] = {2, 3};
//        }
//        if(dp[s][1] + c3[v] < dp[s][3] + c1[v]){
//            dp[v][2] = dp[s][1] + c3[v];
//            son[v][2] = {3, 1};
//        }else{
//            dp[v][2] = dp[s][3] + c1[v];
//            son[v][2] = {1, 3};
//        }
//        if(dp[s][1] + c2[v] < dp[s][2] + c1[v]){
//            dp[v][3] = dp[s][1] + c2[v];
//            son[v][3] = {2, 1};
//        }else{
//            dp[v][3] = dp[s][2] + c1[v];
//            son[v][3] = {1, 2};
//        }
//    }
//}

struct item{
    vector<int> r;
    item(int q, int w, int e){
        r.push_back(q);
        r.push_back(w);
        r.push_back(e);
    }
};

void dfs(int v, int pr = -1){
    t.push_back(v);
    for(auto i : g[v]){
        if(i != pr){
            dfs(i, v);
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    g.resize(n + 1);
    c.resize(n + 1);
//    dp.resize(n + 1);
    for(int i = 1;i <= n;i++){
        c[i].resize(4);
        cin >> c[i][1];
//        dp[i].resize(4);
    }
    for(int i = 1;i <= n;i++){
        cin >> c[i][2];
    }
    for(int i = 1;i <= n;i++){
        cin >> c[i][3];
    }
    for(int i = 0;i < n - 1;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ind = -1;
    for(int i = 1;i <= n;i++){
        if(g[i].size() > 2){
            cout << -1;
            rr;
        }else if(g[i].size() == 1){
            ind = i;
        }
    }
    dfs(ind);
    vector<item> kek;
    kek.push_back(item(1, 2, 3));
    kek.push_back(item(1, 3, 2));
    kek.push_back(item(2, 1, 3));
    kek.push_back(item(2, 3, 1));
    kek.push_back(item(3, 1, 2));
    kek.push_back(item(3, 2, 1));
    vector<int> pp(n + 1);
    int ans = 1e15;
    for(int i = 0;i < kek.size();i++){
        int tmp = 0;
        for(int j = 0;j < t.size();j++){
            tmp += c[t[j]][kek[i].r[j % 3]];
        }
        if(ans > tmp){
            ans = tmp;
            for(int j = 0;j < t.size();j++){
                pp[t[j]] = kek[i].r[j % 3];
            }
        }
        
    }
    cout << ans << endl;
    for(int i = 1;i <= n;i++){
        cout << pp[i] << " ";
    }
    rr;
}
