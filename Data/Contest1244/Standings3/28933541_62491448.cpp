#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++)
#define ltype int
#define rep(i,j,k) for(ltype(i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(ltype(i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(ltype(i)=(j);(i)>=(k);(i)--)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false)
const int inf=0x3f3f3f3f,mod=1000000007;
const double pi=3.1415926535897932,eps=1e-6;
int n,c[4][100005],deg[100005],p[5]={1,2,3},col[100005];vector<int> v[100005];vector<int> ord,cur,ans;
void dfs(int x,int fa){
    ord.pb(x);
    rap(i,0,v[x].size()){
        if(v[x][i]==fa) continue;
        dfs(v[x][i],x);
    }
}
ll check(int x){
    ll res=0;
    rep(i,0,2) col[i]=p[i],res+=c[col[i]][ord[i]],cur[ord[i]]=col[i];
    rap(i,3,n){
        rep(j,1,3) if(j!=col[i-1]&&j!=col[i-2]) col[i]=j,res+=c[j][ord[i]],cur[ord[i]]=col[i];
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    rep(j,1,3)
    rep(i,1,n) scanf("%d",&c[j][i]);
    rap(i,1,n){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        v[t1].pb(t2);v[t2].pb(t1);deg[t1]++;deg[t2]++;
    }
    rep(i,1,n) if(deg[i]>2){puts("-1");return 0;}
    cur.resize(n+2);ans.resize(n+2);
    int id=0;
    rep(i,1,n) if(deg[i]==1) {id=i;break;}
    dfs(id,0);
    ll an=1e18;
    do{
        ll cost=check(1);
        if(an>cost) an=cost,ans=cur;
    }while(next_permutation(p,p+3));
    printf("%lld\n",an);
    rep(i,1,n) printf("%d ",ans[i]);
    return 0;
}