#include <bits/stdc++.h>
 
using namespace std;

const int N = 100100;

set <int> g[N];
int n;

void dfs(int v, set <int> &ver){
    // cout <<"this is ver -- " <<v <<'\n';
    ver.erase(v);
    g[v].insert(0);
    g[v].insert(n + 1);
    for (auto it = g[v].begin(); it != g[v].end(); ++it){
        if (it == g[v].begin()){
            continue;
        }
        while (ver.size() > 0){
            it--;
            auto prev = it;
            it++;
            auto l = ver.upper_bound(*prev);
            if (l == ver.end()){
                break;
            } else if (*l >= *it){
                break;
            } else {
                ver.erase(l);
                dfs(*l, ver);
            }
        }
    }
}

int main(){
    int m;
    cin >>n >>m;
    for (int i=0; i<m; ++i){
        int a, b;
        cin >>a >>b;
        g[a].insert(b);
        g[b].insert(a);
    }
    set <int> ver;
    for (int i=1; i<=n; ++i){
        ver.insert(i);
    }
    int cnt = 0;
    while (ver.size() > 0){
        cnt++;
        dfs(*ver.begin(), ver);
    }
    cout <<cnt - 1 <<'\n';
    return 0;
}