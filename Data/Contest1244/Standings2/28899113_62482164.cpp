#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define int long long

using namespace std;

const int MX=1e5+9;
vector <int> adj[MX],line;
int mrk[MX],col[MX];

DFS(int u){
    line.pb(u);
    mrk[u]=1;
    for(int i=0;i<adj[u].size();i++){
        if(mrk[adj[u][i]]==0){
            DFS(adj[u][i]);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    pair <int,int> ans;
    int a[4][n+1];
    for(int j=1;j<4;j++){
        for(int i=1;i<=n;i++){
            cin>>a[j][i];
        }
    }

    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size()>2){
            cout<<-1;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(adj[i].size()==1){
            DFS(i);
        }
    }
    int minn=1e18;
    for(int i=1;i<=3;i++){
        for(int j=1;j<4;j++){
            if(i!=j){
                int cost=0;
                int k;
                if(i==1){
                    if(j==2){
                        k=3;
                    }
                    else{
                        k=2;
                    }
                }
                if(i==2){
                    if(j==3){
                        k=1;
                    }
                    else{
                        k=3;
                    }
                }
                if(i==3){
                    if(j==2){
                        k=1;
                    }
                    else{
                        k=2;
                    }
                }
                for(int z=0;z<n;z++){
                    if(z%3==0){
                        cost+=a[i][line[z]];
                    }
                    if(z%3==1){
                        cost+=a[j][line[z]];
                    }
                    if(z%3==2){
                        cost+=a[k][line[z]];
                    }
                }
                if(minn>cost){
                    minn=min(minn,cost);
                    ans.F=i;
                    ans.S=j;
                }
            }
        }
    }
    cout<<minn<<endl;
    int i=ans.F;
    int j=ans.S;
    int k;
    if(i==1){
        if(j==2){
            k=3;
        }
        else{
            k=2;
        }
    }
    if(i==2){
        if(j==3){
            k=1;
        }
        else{
            k=3;
        }
    }
    if(i==3){
        if(j==2){
            k=1;
        }
        else{
            k=2;
        }
    }
    for(int z=0;z<n;z++){
        if(z%3==0){
            col[line[z]]=i;
        }
        if(z%3==1){
            col[line[z]]=j;
        }
        if(z%3==2){
            col[line[z]]=k;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<col[i]<<" ";
    }
    return 0;
}
