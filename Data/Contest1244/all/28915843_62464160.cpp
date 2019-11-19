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
    int T;
    cin>>T;
    while(T--)
    {
        int a,b,c,d,k,ans1,ans2;
        cin>>a>>b>>c>>d>>k;
        ans1=a/c+(a%c>0);
        ans2=b/d+(b%d>0);
        if(ans1+ans2<=k) cout<<ans1<<' '<<ans2<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
