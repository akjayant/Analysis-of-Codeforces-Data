#include <bits/stdc++.h>
using namespace std;
int const N = 1e5+9;
int c[4][N];
vector<int> adj[N];
vector<int> v;
void dfs(int node , int p){
    v.push_back(node);
    for(auto i : adj[node]){
        if(i != p){
            return dfs(i , node);
        }
    }
}
int n;
int main(){
    cin>>n;
    for(int i = 1;i<=3;i++)
        for(int j = 1;j<=n;j++)
            cin>>c[i][j];
        
    for(int i = 0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int start = -1;
    for(int i = 1;i<=n;i++){
        if(adj[i].size() > 2){
            return cout<<-1,0;
        }
        if(adj[i].size() == 1){
            start = i;
        }
    }
    dfs(start, start);
    int ans[n+1];
    vector<int> it;
    long long mn = 1e18;
    for(int i = 1;i<=3;i++){
        for(int j = 1;j<=3;j++){
            if(i == j)
                continue;
            long long cur = 0;
            vector<int> ptt = {i , j};
            for(int x= 1;x<=3;x++){
                if(x != i && x != j){
                    ptt.push_back(x);
                    break;
                }
            }
            int pt = 0;
            for(auto k : v){
                cur += c[ptt[(pt)%3]][k];
                pt++;
            }
            if(cur < mn){
                mn = cur;
                it = ptt;
            }
        }
    }
    cout<<mn<<'\n';
    int pt = 0;
    for(auto i : v){
        ans[i] = it[pt%3];
        pt++;
    }
    for(int i = 1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}