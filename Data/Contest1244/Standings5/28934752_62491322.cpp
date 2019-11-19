#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
vector<int> g[N];
ll c[N][3];
int n;
ll d[N][3][3],f[N][3][3];
int fat[N],last,root;
int ans[N];
void dfs(int x,int fa){
    for(int i=0;i<g[x].size();i++){
        int y = g[x][i];
        if(y == fa)continue;
        fat[y] = x;
        for(int k = 0;k<3;k++){
            for(int j=0;j<3;j++){
                for(int o=0;o<3;o++){
                    if(k == j || j == o || k == o)continue;
                    if(d[y][k][j] > d[x][j][o] + c[y][k]){
                        d[y][k][j] = d[x][j][o] + c[y][k];
                        f[y][k][j] = o;
                    }
                }
            }
        }
        dfs(y,x);
    }
    if(g[x].size() == 1 && x != root){
        last = x;
    }
}
void getans(int x,int k,int j){
    ans[x] = k;
    if(x == root)return;
    getans(fat[x],j,f[x][k][j]);
}
int main(){
    scanf("%d",&n);
    for(int k=0;k<3;k++)
    for(int i=1;i<=n;i++)scanf("%lld",&c[i][k]);

    for(int i=1;i<=n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(g[i].size() > 2){
            puts("-1");return 0;
        }
        if(g[i].size() == 1){
            root = i;
        }
    }
    memset(d,0x3f,sizeof d);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i == j)continue;
            d[root][i][j] = c[root][i];
        }
    }
    //cout << root << endl;
    dfs(root,0);
    //cout << last << endl;
    ll res = 1e18;
    int rk,rj;
    for(int k=0;k<3;k++){
        for(int j=0;j<3;j++){
            if(k == j)continue;
            if(res > d[last][k][j]){
                res = d[last][k][j];
                rk = k;
                rj = j;
            }
        }
    }
    //cout << res << endl;
    getans(last,rk,rj);
    printf("%lld\n",res);
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]+1);
    }
    return 0;
}