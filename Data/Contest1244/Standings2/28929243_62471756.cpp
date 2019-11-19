#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define M 1000000007
#define sz(a) (ll)a.size()
#define pll pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define sep(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define mll map<ll,ll>
#define vl vector<ll>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define F first
#define S second
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll ans=n;
        rep(i,0,n)
        {
            if(s[i]=='1')
                ans=max(ans,max(i+1,n-i)*2);
        }
        ll dp[n+1][2]={0};
        sep(i,n-1,0)
        {
            dp[i][0]=1+dp[i+1][0];
            dp[i][1]=1+dp[i+1][1];
            if(s[i]=='1')
            {
                dp[i][0]=max(dp[i][0],2+dp[i+1][1]);
                dp[i][1]=max(dp[i][1],2+dp[i+1][0]);
            }
            ans=max(ans,max(dp[i][0],dp[i][1]));
        }
        cout<<ans<<"\n";
    }
}
