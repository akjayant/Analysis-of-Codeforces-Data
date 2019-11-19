#include <bits/stdc++.h>
using namespace std;
const int NMAX=1e5+4;

int n,c[NMAX][4],col[5],poz;
long long sol=1e18,S;
bool used[NMAX];
vector <int> g[NMAX];
int v[NMAX],ans[NMAX];

void dfs(int node, int nr){
    used[node]=1;
    v[node]=col[nr];
    S+=c[node][col[nr]];
    for(auto it:g[node]){
        if(!used[it]){
            dfs(it, (nr+1)%4 + !((nr+1)%4));
        }
    }
}

int main(){
    int x,y;
    bool ok=1;
    cin>>n;
    for(int i=1;i<=n;++i){
        scanf("%d", &c[i][1]);
    }
    for(int i=1;i<=n;++i){
        scanf("%d", &c[i][2]);
    }
    for(int i=1;i<=n;++i){
        scanf("%d", &c[i][3]);
    }
    for(int i=1;i<n;++i){
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;++i){
        if(g[i].size() == 1){
            x=i;
            y=g[i][0];
        }
        if(g[i].size() == 3){
            ok=0;
            break;
        }
    }
    if(!ok){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=3;++i){
        for(int j=1;j<=3;++j){
            if(i == j)
                continue;
            col[1]=i;
            col[2]=j;
            for(int q=1;q<=3;++q)
                if(q!=i && q!=j)
                    col[3]=q;

            for(int q=1;q<=n;++q)
                used[q]=0;
            used[x]=used[y]=1;

            S=c[x][i];
            v[x]=i;

            dfs(y,2);

            if(S<sol){
                sol=S;
                for(int i=1;i<=n;++i){
                    ans[i]=v[i];
                }
            }
        }
    }
    cout<<sol<<'\n';
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<' ';
    return 0;
}
