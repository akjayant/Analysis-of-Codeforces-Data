#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#define BUG puts("no bug")
#define sci(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define REP(a,b,c) for(ll a=b;a<=c;a++)
#define PER(a,b,c) for(ll a=b;a>=c;a--)
#define ll long long
#define lb(a) (a&(-a))
using namespace std;
const ll MAXN=1e5+5;
ll n,m,t;
vector<ll>maps[MAXN];
ll cost[MAXN][3];
ll tmpcolor[MAXN];
ll anscolor[MAXN];
ll ans;
ll ori=0;

ll dfs(ll x,ll pre,ll pree,ll prenode)
{
    if(maps[x].size()==1)
    {
        ll flag;
        REP(j,0,2)if(j!=pre&&j!=pree)flag=j;
        tmpcolor[x]=flag;
        return cost[x][flag];
    }
    for(ll i=0;i<maps[x].size();i++)
    {
        ll to=maps[x][i];
        if(to==prenode)continue;
        ll flag;
        REP(j,0,2)if(j!=pre&&j!=pree)flag=j;
        tmpcolor[x]=flag;
        return cost[x][flag]+dfs(to,flag,pre,x);
    }
}

int main()
{
    cin>>n;
    REP(i,1,n)scl(cost[i][0]);
    REP(i,1,n)scl(cost[i][1]);
    REP(i,1,n)scl(cost[i][2]);
    REP(i,1,n-1)
    {
        ll a,b;
        scl(a);
        scl(b);
        maps[a].push_back(b);
        maps[b].push_back(a);
    }
//    cout<<maps[2].size()<<endl;
    REP(i,1,n)if(maps[i].size()>2){cout<<"-1";return 0;}
    ll ans=1e18;
    ll flag=0;
    REP(i,1,n)if(maps[i].size()==1)ori=i;
    ll sec=maps[ori][0];
    ll san;
    for(ll i=0;i<maps[sec].size();i++)if(maps[sec][i]!=ori)san=maps[sec][i];
//    cout<<ori<<sec<<san<<endl;
    REP(i,0,2)
    {
        REP(j,0,2)
        {
            if(i==j)continue;
            flag=1;
            ll tmp=cost[ori][i]+cost[sec][j]+dfs(san,j,i,sec);
//            cout<<tmp<<endl;
            if(ans>tmp)
            {
                ans=tmp;
                tmpcolor[ori]=i;
                tmpcolor[sec]=j;
                REP(k,1,n)anscolor[k]=tmpcolor[k];
            }
        }
    }
    cout<<ans<<endl;
    cout<<anscolor[1]+1;
    REP(i,2,n)cout<<' '<<anscolor[i]+1;
}
