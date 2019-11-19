#include<bits/stdc++.h>
#include<algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include  <stdio.h>
#include   <math.h>
#include   <time.h>
#include   <vector>
#include   <bitset>
#include    <queue>
#include      <map>
#include      <set>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((long long)(x).size())
#define mod Mod
#define LL ll
typedef vector<long long> VI;
typedef pair<long long,long long> PII;

typedef long long ll;
const int maxn = 2e5 + 5;
const ll Mod = 1e9 + 7;
ll powmod(ll a,ll b) {ll res=1;a%=Mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%Mod;a=a*a%Mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//head
struct haha{
    vector<int> vec;
    int vecnum;
    int cos[4];
}edg[maxn];

inline void Add(int u,int v){
    edg[u].vec.push_back(v);
    edg[u].vecnum ++;
}

inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

struct ha66{
    int o,fa,o_col,fa_col;
};

    int n;
    int col[maxn];
    ll res;
    ha66 que[maxn];

void chu(int o,int fa,int o_col,int fa_col){
    res = edg[o].cos[o_col] + edg[fa].cos[fa_col];
    int qtot = 2;
    que[1] = {o,fa,o_col,fa_col};
    col[o] = o_col;
    col[fa] = fa_col;
    que[2] = {fa,o,fa_col,o_col};
    int now = 1;
    while(now <= qtot){
//        if(now <= 10) cout << now << " " << que[now].fa << " " << que[now].o << endl;
//        printf("%d\n",qtot);
        for(int oo = 0;oo < edg[que[now].o].vecnum;++ oo){
            int v = edg[que[now].o].vec[oo];
            if(v == que[now].fa) continue;

//            if(qtot <= 10) printf("%d %d oo : %d %d %d %d\n",qtot,now,oo,que[now].o,que[now].fa,v);

            ++ qtot;
            que[qtot] = {v,que[now].o,6-que[now].fa_col-que[now].o_col,que[now].o_col};
            col[v] = 6-que[now].fa_col-que[now].o_col;
            res += edg[v].cos[6-que[now].fa_col-que[now].o_col];

//            if(qtot <= 10) printf("     %d %d oo : %d %d %d %d\n",qtot,now,oo,que[now].o,que[now].fa,v);
        }
        ++ now;
//        cout << "----------------" << now << endl;
    }
}

void solve(){
    int jj = edg[1].vec[0];
    ll rres = Mod * Mod,res1,res2;
    rep(i,1,3)
        rep(j,1,3)
            if(i != j){
                res = Mod * Mod;
                chu(1,jj,i,j);
                if(res < rres){
                    rres = res;
                    res1 = i;
                    res2 = j;
                }
            }
    cout << rres << endl;
    chu(1,jj,res1,res2);
    rep(i,1,n) printf("%d ",col[i]);
}

int main()
{
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	scanf("%d",&n);
	rep(j,1,3)
        rep(i,1,n){
            edg[i].cos[j] = read();
        }
    rep(i,1,n-1){
        int u,v;
        u = read();
        v = read();
        Add(u,v);
        Add(v,u);
    }
    rep(i,1,n){
        if(edg[i].vecnum >= 3){
            printf("-1\n");
            return 0;
        }
    }
    res = Mod * Mod;
    if(n == 1){
        rep(i,1,3) res = min(res,1ll*edg[1].cos[i]);
        cout << res << endl;
        return 0;
    }
    else if(n == 2){
        rep(i,1,3)
            rep(j,1,3)
                if(i != j)
                    res = min(res,1ll*(edg[1].cos[i]+edg[2].cos[j]));
        cout << res << endl;
        return 0;
    }
    solve();
    return 0;
}
