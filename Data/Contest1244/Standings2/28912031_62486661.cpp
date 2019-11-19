#include<bits/stdc++.h>
#define ll long long
#define zp push_back
#define zm make_pair
#define zl lower_bound
#define z1 first
#define z2 second
using namespace std;
int z(){int z;scanf("%d",&z);return z;}

const int M = 1e5+5;
int n;
vector<int>g[M];
int c[M][4];
int in[M];
int idx[M], step;
void dfs(int u, int F){
    idx[++ step] = u;
    for(auto v : g[u]){
        if(v!=F)dfs(v, u);
    }
}
int ans[M];
int ans2[M];
int co[M];

void cal(){
    n = z();
    for(int t=1;t<=3;t++)
    for(int i=1;i<=n;i++){
        c[i][t] = z();
    }
    for(int i=1;i<n;i++){
        int x, y;
        x =z();
        y=z();
        in[x] ++;
        in[y] ++;
        if(in[x]>2 || in[y]>2){
            printf("-1\n");
            return;
        }
        g[x].zp(y);
        g[y].zp(x);
    }
    int R = -1;
    for(int i=1;i<=n;i++){
        if(in[i]==1){
            R = i;
            break;
        }
    }
    dfs(R, -1);
    ll mi = 1e16;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++)if(j-i){
            co[1]=i;co[2]=j;
            ll t = c[idx[1]][i] + c[idx[2]][j];
            for(int L=3;L<=n;L++){
                int an = 6-co[L-1]-co[L-2];
                co[L] = an;
                t += c[idx[L]][an];
            }
            if(mi > t){
                mi = t;
                for(int L=1;L<=n;L++)ans[idx[L]] = co[L];
            }
        }
    }
    cout<<mi<<endl;
    for(int i=1;i<=n;i++)printf("%d%c", ans[i], " \n"[i==n]);
}
int main(){
    cal();
}
