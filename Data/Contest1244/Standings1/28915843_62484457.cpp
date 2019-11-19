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

int a[100005];
int main()
{
    ios::sync_with_stdio(false);
    int i,j,n,ans;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    ans=a[n]-a[1];
    for(i=1;i<=n&&a[i]==a[i+1];i++);
    for(j=n;j>=1&&a[j]==a[j-1];j--);
    while(i<j)
    {
        int t=false;
        if(i<n-j+1)
        {
            ll k=min(m/i,ll(a[i+1]-a[i]));
            if(k>0) t=true;
            m-=k*i;
            ans-=k;
            for(i++;i<=n&&a[i]==a[i+1];i++);
        }
        else
        {
            ll k=min(m/(n-j+1),ll(a[j]-a[j-1]));
            if(k>0) t=true;
            m-=k*(n-j+1);
            ans-=k;
            for(j--;j>=1&&a[j]==a[j-1];j--);
        }
        if(!t) break;
    }
    cout<<ans<<endl;
    return 0;
}
