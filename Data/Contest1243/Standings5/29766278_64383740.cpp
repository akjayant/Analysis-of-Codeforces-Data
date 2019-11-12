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
    for(ll j=0;j<t;j++)
    {
        cin >> n;
        string s1,s2;
        cin >> s1;
        cin >> s2;
        if(s1==s2)
        {
            cout << "Yes\n";
            continue;
        }
        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
                v.pb(i);
        }
        if(v.size()!=2 )
        {
            cout << "No\n";
            continue;
        }
        if(s1[v[0]]!=s1[v[1]] || s2[v[0]]!=s2[v[1]] )
        {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }
    return 0;
}
