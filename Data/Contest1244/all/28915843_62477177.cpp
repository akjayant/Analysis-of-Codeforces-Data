#include<bits/stdc++.h>
#include<bits/extc++.h>
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define lb lower_bound
#define ub upped_bound
#define fbo find_by_order
#define ofk order_of_key
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
template<class T>using pq=__gnu_pbds::priority_queue<T,greater<T>,pairing_heap_tag>;
template<class T>using tr=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int a[5][100005],b[100005],anss[100005],p[5],ansp[5],num;
vector<int>e[100005];
void dfs(int i,int f)
{
    b[++num]=i;
    for(auto j:e[i]) if(j!=f)
    {
        dfs(j,i);
        break;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    ll ans=0x3f3f3f3f3f3f3f3fll;
    cin>>n;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        e[x].eb(y);
        e[y].eb(x);
    }
    for(int i=1;i<=n;i++) if(e[i].size()==1)
    {
        dfs(i,0);
        break;
    }
    if(num!=n)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<=3;i++) p[i]=i;
    do
    {
        ll sum=0;
        for(int i=1;i<=n;i++) sum+=a[p[i%3+1]][b[i]];
        if(ans>sum)
        {
            ans=sum;
            memcpy(ansp,p,sizeof(p));
        }
    }
    while(next_permutation(p+1,p+4));
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) anss[b[i]]=ansp[i%3+1];
    for(int i=1;i<=n;i++) cout<<anss[i]<<' ';
    cout<<endl;
    return 0;
}
