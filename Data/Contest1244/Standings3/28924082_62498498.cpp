#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define endl '\n'
#define ld long double
#define FOR(i,a,n) for (ll i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (ll i=(n);i>=(a);--i)
#define FI(i,n) for (ll i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define MINUS(a) memset((a),-1,sizeof((a)))
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(),g.end()
#define sz(x) (ll)x.size()
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
 
// I want to be the very best, like no one ever was, I will battle everyday to claim my rightful place
// Not gonna give up until it's over
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
// I am questioning life and universe and 
// everything else after looking at this

const ll MAXN = 1e5 + 10;
ll a[MAXN];
ll n,k; 
ll high[MAXN],low[MAXN];

void solve(){
    cin>>n>>k;

    FOR(i,1,n){
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    ll sum = 1;
    FOR(i,2,n){
        ll num = a[i] - a[i-1];
        high[i] = high[i-1] + num*sum;
        sum++;
    }

    sum = 1;
    RFOR(i,1,n-1){
        ll num = a[i+1] - a[i];
        low[i] = low[i+1] + num*sum;
        sum++;
    }

    ll ans = a[n] - a[1];
    ll s = 1, e = n;

    ll prev_sum = 1,ahead_sum = 1;
    while(s <= e){
        if(prev_sum >= ahead_sum){
            if(ahead_sum * (a[e] - a[e-1]) <= k){
                k = k - ahead_sum*(a[e]-a[e-1]);
                e--;
                ans = min(ans,a[e] - a[s]);
                ahead_sum++;
            }else {
                ll jaana = k/(ahead_sum);
                ans = min(ans,a[e] - jaana - a[s]);
                break;
            }
        }else {
            if(prev_sum*(a[s+1] - a[s]) <= k){
                
                k = k - prev_sum*(a[s+1]-a[s]);
                s++;
                ans = min(ans,a[e] - a[s]);
                prev_sum++;
            }else {
                ll jaana = k/(prev_sum);
                ans = min(ans,a[e] - jaana - a[s]);

                break;
            }
        }
    }
    ans = max(ans,0LL);

    cout<<ans<<endl;
}

signed main(){
 
   FastRead;    
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t;
    t = 1; 
    // cin>>t;
    FOR(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}