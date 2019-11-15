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
    ll k,n;
    cin >> k;
    while(k--)
    {
        cin >> n;
        string s,t;
        cin >> s;
        cin >> t;
        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            if(s[i]!=t[i])
                v.pb(i);
        }
        if(v.empty())
        {
            cout << "Yes\n";
            cout << 1 << "\n";
            cout << 1 << " " << 1 << "\n";
            continue;
        }
        vector< pp > ans;
        for(ll i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                bool found=false;
                for(ll j=i+1;j<n;j++)
                {
                    if(t[j]==s[i])
                    {
                        ans.pb(mp(j+1,j+1));
                        swap(t[j],s[j]);
                        ans.pb(mp(j+1,i+1));
                        swap(s[j],t[i]);
                        found=true;
                        break;
                    }
                }
                if(!found)
                {
                    for(ll j=i+1;j<n;j++)
                    {
                        if(s[j]==s[i])
                        {
                            ans.pb(mp(j+1,i+1));
                            swap(s[j],t[i]);
                            break;
                        }
                    }
                }
            }
        }
        if(ans.size()>(2*n) || s!=t)
        {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        cout << ans.size() << "\n";
        for(ll i=0;i<ans.size();i++)
            cout << ans[i].X << " " << ans[i].Y << "\n";
    }
    return 0;
}
