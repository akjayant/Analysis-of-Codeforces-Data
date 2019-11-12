#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((int)(1e7))
#define MAX_X ((int)(1e6 + 2))
#define pi (2.0*acos(0))
#define M ((ll)(1e9 + 7))
#define NN ((ll)(305))
#define N ((int)(1e6 + 5))
#define eps (0)
#define log 20


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;


typedef tree < ll,  null_type,  less < ll >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;

ll power(ll n , ll p)
{
    if(p==0) return 1;
    ll ans = power(n,p/2);
    ans = ans*ans%M;
    if(p%2==1) ans = ans*n%M;
    return ans;
}

int main()
{
    int n , m;
    cin>>n>>m;
    ll ans = power(2,m) - 1 + M;
    ans %= M;
    ans = power(ans,n);
    cout<<ans<<endl;
    return 0;
}
