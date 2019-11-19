#include <bits/stdc++.h>
using namespace std;
#define re return
#define ll long long
#define du double
#define co continue
#define gcd __gcd
#define br break
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
ll color[5][100000+10];
vector <ll> tree[100000+10];
ll colors[100000+10];
ll g;
void dfs(ll u,ll c1, ll c2){
    for (int i=0;i<tree[u].size();++i){
        if (colors[tree[u][i]]==0){
            g=1;
            while (g==c1 || g==c2) g++;
            colors[tree[u][i]]=g;
            dfs(tree[u][i],c2,g);
        }
    }
}
int main()
{
    fast();
    ll n;
    cin >> n;
    for (int i=1;i<=3;++i){
        for (int j=1;j<=n;++j){
            cin >> color[i][j];
        }
    }
    ll u,v;
    for (int i=1;i<=n-1;++i){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i=1;i<=n;++i){
        if (tree[i].size()>2){
            cout << -1;
            re 0;
        }
    }
    ll ans=1000000000000000000;
    ll sum;
    for (int i=1;i<=n;++i){
        if (tree[i].size()==1){
            for (int j=1;j<=3;++j)
            for (int z=1;z<=3;++z){
                if (z==j) co;
                for (int i=1;i<=n;++i)colors[i]=0;
                sum=0;
                colors[i]=j;
                colors[tree[i][0]]=z;
                dfs(tree[i][0],colors[i],colors[tree[i][0]]);
                for (int i=1;i<=n;++i){
                    sum+=color[colors[i]][i];
                }
                ans=min(ans,sum);
            }
            cout << ans << endl;
            for (int j=1;j<=3;++j)
            for (int z=1;z<=3;++z){
                if (z==j) co;
                for (int i=1;i<=n;++i)colors[i]=0;
                sum=0;
                colors[i]=j;
                colors[tree[i][0]]=z;
                dfs(tree[i][0],colors[i],colors[tree[i][0]]);
                for (int i=1;i<=n;++i){
                    sum+=color[colors[i]][i];
                }
                if (sum==ans){
                    for (int i=1;i<=n;++i) cout << colors[i] << " ";
                    re 0;
                }
            }
            re 0;
        }
    }
    re 0;
}
