//scnucjh
#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 1e5+100;
vector<int> G[maxn];
int n;
int c[3][maxn];
int dep[maxn];

int color[maxn];

void dfs(int u,int f,int d) {
    dep[u] = d;
    for(auto v:G[u]) {
        if(v==f) continue;
        dfs(v,u,d+1);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.txt", "r", stdin);
#endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[0][i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[1][i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[2][i]);
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
        if(G[u].size()>2 || G[v].size()>2) {
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++) {
        if(G[i].size()==1) {
            dfs(i,0,0);
            break;
        }
    }

    int a[3] = {0,1,2};
    long long ans = 1ll<<62;
    do {
        long long tmp = 0;
        for(int i=1;i<=n;i++) {
            int x=dep[i]%3;
            x = a[x];
            tmp += c[x][i];
        }
        if(tmp<ans) {
            ans = tmp;
            for(int i=1;i<=n;i++) {
                int x=dep[i]%3;
                x = a[x];
                color[i] = x+1;
            }
        }
    }while(next_permutation(a, a+3));
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++) printf("%d ",color[i]);
    return 0;
}


