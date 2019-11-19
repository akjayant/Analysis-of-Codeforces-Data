#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
void test(){cerr<<"\n";}
template<typename T,typename... Args>void test(T x,Args... args){cerr<<x<<" ";test(args...);}
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAXN=(int)1e5+5;
const int MOD=(int)1e9+7;
vector<int>ve[MAXN];
int cost[MAXN][3];
int col[MAXN],cc[MAXN];
vector<int>st;
void dfs(int u,int pre){
    st.push_back(u);
    for(auto v:ve[u]){
        if(v!=pre)dfs(v,u);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<3;i++){
        for(int j=1;j<=n;j++){
            cin>>cost[j][i];
        }
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(ve[i].size()>2){
            cout<<-1<<"\n";
            return 0;
        }
    }
    int rt=1;
    while(ve[rt].size()>1)rt++;
    dfs(rt,-1);
    ll ans=(ll)1e18;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i!=j){
               cc[st[0]]=i;
               cc[st[1]]=j;
                ll tmp=cost[st[0]][i]+cost[st[1]][j];
                for(int k=2;k<n;k++){
                    int tmpc=3-cc[st[k-1]]-cc[st[k-2]];
                    cc[st[k]]=tmpc;
                    tmp+=cost[st[k]][tmpc];
                }
                if(tmp<ans){
                    ans=tmp;
                    swap(col,cc);
                }

            }
        }
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++)cout<<col[i]+1<<" ";
    cout<<"\n";
    return 0;
}
