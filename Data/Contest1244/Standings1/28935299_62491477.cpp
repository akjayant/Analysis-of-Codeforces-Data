#include <bits/stdc++.h>
#define pi acos(-1)
using namespace std;
const int N=1e5+10, base=1e9+123;
long long cur=0;
int n,cost[3][N],col[N];
vector<int> vec,adj[N];
void dfs(int u,int pa,int t){
    int i=vec[t%3];
    cur+=cost[i][u];
    for(auto v:adj[u]){
        if(v!=pa) dfs(v,u,t+1);
    }
}
void calc(int u,int pa,int t){
    col[u]=vec[t%3]+1;
    for(auto v:adj[u]){
        if(v!=pa) calc(v,u,t+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=0;i<3;i++){
        for(int j=1;j<=n;j++) cin>>cost[i][j];
    }
    int deg=0;
    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg=max(deg,max((int)adj[u].size(),(int)adj[v].size()));
    }
    if(deg>2) return cout<<-1,0;
    long long ans=-1;
    for(int i=1;i<=n;i++){
        if(adj[i].size()==1){
            vec.resize(3);
            vector<int> temp;
            iota(vec.begin(),vec.end(),0);
            do{
                cur=0;
                dfs(i,i,0);
                if(ans==-1){
                    ans=cur;
                    temp=vec;
                }
                else if(cur<ans){
                    ans=cur;
                    temp=vec;
                }
            }while(next_permutation(vec.begin(),vec.end()));
            cout<<ans<<'\n';
            vec=temp;
            calc(i,i,0);
            for(int u=1;u<=n;u++) cout<<col[u]<<' ';
            return 0;
        }
    }
    return 0;
}
