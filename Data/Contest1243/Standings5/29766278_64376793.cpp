#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb(x) push_back(x);
#define mp(x,y) make_pair(x,y)
#define X first
#define Y second
typedef long long int ll;
typedef pair<ll,ll> pp;

#define debug(x) cout << #x << " :: "<< x <<"\n";
#define debug2(x,y) cout << #x << " :: "<< x << "\t" << #y << " :: " << y << "\n";
#define debug3(x,y,z) cout << #x << " :: "<< x << "\t" << #y << " :: " << y << "\t" << #z << " :: " << z << "\n";
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree< pair<ll,ll> , null_type,less< pair<ll,ll> >, rb_tree_tag,tree_order_statistics_node_update>

int main()
{
    boost
    ll t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll a[n];
        for(ll i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n);
        ll ans=1;
        for(ll i=1;i<=n;i++)
        {
            ll cnt=0;
            for(ll j=0;j<n;j++)
            {
                if(a[j]>=i)
                    cnt++;
            }
            if(cnt>=i)
                ans=max(ans,i);
        }
        cout << ans << "\n" ;
    }
    return 0;
}
