#include<bits/stdc++.h>

using namespace std;

int c[3][100005],ans[6][100005],p[6][3];
vector<int>v[100005];
bool vis[100005];
long long cst;

void dfs(int u,int cur,int now)
{
    //cout<<u<<' '<<cur<<' '<<now<<endl;
    int i;cst += c[p[now][cur]][u];ans[now][u] = p[now][cur];
    for(i=0;i<v[u].size();i++){
        if(vis[v[u][i]])continue;
        vis[v[u][i]]=true;
        dfs(v[u][i],(cur+1)%3,now);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,x,y,i,j,leaf,idx;
    long long mn = 1e16;
    cin>>n;
    for(j=0;j<3;j++){
        for(i=1;i<=n;i++)cin>>c[j][i];
    }
    for(i=0;i<n-1;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i=1;i<=n;i++){
        if(v[i].size()>2){
            cout<<"-1\n";
            return 0;
        }
        if(v[i].size()==1)leaf = i;
    }
    p[0][0]=0;p[0][1]=1;p[0][2]=2;
    p[1][0]=0;p[1][1]=2;p[1][2]=1;
    p[2][0]=1;p[2][1]=0;p[2][2]=2;
    p[3][0]=1;p[3][1]=2;p[3][2]=0;
    p[4][0]=2;p[4][1]=0;p[4][2]=1;
    p[5][0]=2;p[5][1]=1;p[5][2]=0;
    for(j=0;j<6;j++){
        memset(vis,false,sizeof(vis));
        vis[leaf] = true;cst=0;dfs(leaf,0,j);
        if(cst < mn){
            mn = cst;
            idx = j;
        }
    }
    cout<<mn<<'\n';
    for(i=1;i<=n;i++)cout<<ans[idx][i]+1<<' ';
    cout<<'\n';
	return 0;
}
