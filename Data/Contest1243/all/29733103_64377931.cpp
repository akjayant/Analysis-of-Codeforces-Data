#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define pii 3.14
#define mod (ll)(1000000007)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define pi pair<int,int>
#define N (ll)(1e6+5)

void solve()
{
    ll n;
    cin>>n;

    string s1,s2;
    cin>>s1>>s2;

    if(s1 == s2)
    {
        cout<<"Yes\n";
        return;
    }

    ll cnt = 0;
    char c1,c2,c3,c4;
    for(int i=0;i<n;i++)
    {
        if(s1[i] == s2[i])
            continue;
        if(cnt == 0)
            c1 = s1[i],c2 = s2[i];
        else
            c3 = s1[i] , c4 = s2[i];
        cnt++;
    }
    if(cnt!=2)
    {
        cout<<"No\n";
        return;
    }

    if(c1 == c3 && c2 == c4)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return;
}

int main()
{
    fio;
    ll t;
    t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }

}
