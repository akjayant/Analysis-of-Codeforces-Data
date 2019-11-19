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

int main()
{
    ios::sync_with_stdio(false);
    int d,w;
    ll m,n,p;
    cin>>n>>p>>w>>d;
    m=p/w;
    for(int i=0;i<=w;i++)
    {
        ll k=(p-m*w)/d;
        if(m>=0&&k>=0&&m*w+k*d==p&&k+m<=n)
        {
            cout<<m<<' '<<k<<' '<<n-m-k<<endl;
            return 0;
        }
        m--;
    }
    cout<<-1<<endl;
    return 0;
}
