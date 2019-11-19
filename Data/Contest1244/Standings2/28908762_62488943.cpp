#include<bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define PER(i,a,b) for(int i = a; i >= b; --i)
#define PB push_back
#define MP make_pair
#define fi first
#define se second
typedef long long LL;
typedef double DB;

const int maxn = 1e5;

int n, ci[maxn+5][3];
int num[maxn+5], all;
vector<int> G[maxn+5];
int sol[maxn+5];

void dfs(int x, int p) {
    num[++all] = x;
    int fg = 0;
    for(auto y : G[x]) if(y!=p) {
        if(fg) exit( puts("-1")*0 );
        fg = 1;
        dfs(y, x);
    }
}

int main() {
    scanf("%d", &n);
    REP(k,0,2) REP(i,1,n) scanf("%d", ci[i]+k);
    for(int i = 1, u,v;i < n; ++i) {
        scanf("%d%d", &u, &v);
        G[u].PB(v); G[v].PB(u);
    }
    int rt = 0;
    REP(i,1,n) if(G[i].size() == 1) {
        rt = i;
        break;
    }
    all = 0;
    dfs(rt, 0);
    assert(all == n);
    int fk1 = -1, fk2 = -1, fk3 = -1;
    LL ans = 1e17;
    REP(t1,0,2) REP(t2,0,2) {
        if(t1==t2) continue;
        int t3 = 0;
        if(t3==t1 || t3==t2) ++t3;
        if(t3==t1 || t3==t2) ++t3;
        LL sum = 0;
        for(int i = 1; i <= n; i += 3) sum += ci[ num[i] ][t1];
        for(int i = 2; i <= n; i += 3) sum += ci[ num[i] ][t2];
        for(int i = 3; i <= n; i += 3) sum += ci[ num[i] ][t3];
        if(sum < ans) {
            ans = sum;
            fk1 = t1, fk2 = t2, fk3 = t3;
        }
    }
    for(int i = 1; i <= n; i += 3) sol[ num[i] ] = fk1+1;
    for(int i = 2; i <= n; i += 3) sol[ num[i] ] = fk2+1;
    for(int i = 3; i <= n; i += 3) sol[ num[i] ] = fk3+1;
    printf("%I64d\n", ans);
    REP(i,1,n) printf("%d%c", sol[i], (i==n)?'\n':' ');
    return 0;
}
