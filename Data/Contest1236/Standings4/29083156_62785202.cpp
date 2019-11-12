#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ll long long
#define lld long double
#define mod 1000000007
#define rep(i,n)    for(ll i=0;i<n;++i)
#define forup(i,a,b)    for(ll i=a;i<=b;++i)
#define all(v)    v.begin(),v.end()
#define inf 1000000010
#define pii pair<ll,ll>
#define PI 3.14159265
#define vl vector<ll>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define MAXN 200000
#define bsze 555
#define endl '\n'
#define sz(v) (ll)v.size()
#define flush fflush(stdout)
#define fast  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> order_set;
ll power(ll x,ll y, ll md){ll res = 1;x%=md;while(y>0){if(y&1)res = (res*x)%md;x = (x*x)%md;y = y>>1;}return res%md;}

int main(){
    fast;
    ll a,b,c;
    
    ll ans=0;
    ll t;
    cin>>t;
    while(t--){
        ans =0;
        cin>>a>>b>>c;
        for(ll x=0;x<=a;++x){
            for(ll y=0;y<=c/2;++y){
                if(2*x+y<=b){
                    ans = max(3*x+3*y,ans);
                }
            }
        }
        cout<<ans<<endl;
    }
    
}