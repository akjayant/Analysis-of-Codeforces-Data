#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod = 1e9+7;
const ll maxn = 2005;

struct Node {
    int i,j;
    ll l;
}node[maxn*maxn];
int cnt;

bool operator<(Node a,Node b) {
    return a.l <b.l;
}

int xx[maxn],yy[maxn],kk[maxn],cc[maxn];

int fa[maxn];

int find(int x) {
    return  fa[x]==x?x:fa[x]=find(fa[x]);
}

vector<ll> p;
vector<pll> e;

int main() {

    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d%d",&xx[i],&yy[i]);
    }
    for (int i=1;i<=n;i++) {
        scanf("%d",&cc[i]);
        node[++cnt] = Node{0,i,cc[i]};
        fa[i]=i;
    }
    for (int i=1;i<=n;i++) {
        scanf("%d",&kk[i]);
        for (int j=1;j<i;j++) {
            node[++cnt] = Node{i, j,(kk[i]+kk[j])*1ll*(  abs(xx[i]-xx[j]) + abs(yy[i]-yy[j])  )};
        }
    }

    sort(node+1,node+cnt+1);
    ll ans = 0;
    for (int i=1;i<=cnt;i++) {
        int fi = find(node[i].i);
        int fj = find(node[i].j);
        if (fi!=fj) {
            fa[fi]=fj;
            ans += node[i].l;
            if (node[i].i==0) {
                p.push_back(node[i].j);
            } else {
                e.emplace_back(node[i].i,node[i].j);
            }
        }
    }

    printf("%lld\n",ans);

    printf("%lld\n",1ll*p.size());
    for (ll pp: p) {
        printf("%lld ",pp);
    }
    printf("\n");
    printf("%lld\n",1ll*e.size());
    for (pll pp: e) {
        printf("%lld %lld\n",pp.first,pp.second);
    }


    return 0;
}
