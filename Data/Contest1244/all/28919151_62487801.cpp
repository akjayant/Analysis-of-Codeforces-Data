#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define scanVec(vec , n) for(int i = 0; i < n ; i++){ cin>>vec[i];}
#define printVec(vec , n) for(int i = 0; i < n ; i++){ cout<<vec[i]<<" ";}
#define S second
#define F first
const int  MOD = 1e9 + 7;
const int  N = 1e5 + 7;
vector<int> g[N];
ll c[N][3];
bool been[N];

int main(){
    ios::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
    int n , u , v ; cin>>n;
    for(int j = 0 ; j < 3 ; j++){
        for(int i = 1; i <= n ; i++){
            cin>>c[i][j];
        }
    }
    for(int i = 0 ; i < n - 1; i++){
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int last = 1;
    for(int i = 1 ; i<= n ; i++){
        if(g[i].size() >= 3) {
            cout<<-1<<endl;
            return 0;
        }
        if(g[i].size() == 1) last = i;
    }
    vector<int> m;
    for(int j = 0 ; j < n ; j++){
        m.pb(last);
        been[last] = true;
        for(auto x: g[last]){
            if(been[x]) continue;
            last = x;
        }
    }
    vector<int> col[6];
    vector<int> all; 
    all.pb(0); all.pb(1); all.pb(2);
    col[0].resize(3);
    col[0][0] = all[0];
    col[0][1] = all[1];
    col[0][2] = all[2];
    int i = 1;
    while(next_permutation(all.begin() , all.end())){
        col[i].resize(3);
        col[i][0] = all[0];
        col[i][1] = all[1];
        col[i][2] = all[2];
        i++;
    }
    ll res = LLONG_MAX , col_index = -1;
    for(int ind = 0 ; ind < 6 ; ind++){
        ll tmp = 0;
        for(int i = 0 ; i < n ; i++){
            tmp += c[m[i]][col[ind][i % 3]];
        }
        if(tmp < res){
            res = tmp;
            col_index = ind;
        }
    }
    vector<int> res_cols(n + 1);
    for(int i = 0; i < n ; i++){
        res_cols[m[i]] = col[col_index][i % 3] + 1;
    }
    cout<<res<<endl;
    for(int i = 1; i <= n ; i++){
        cout<<res_cols[i]<<" ";
    }
    cout<<endl;
    return 0;
}