#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long long lint;
typedef pair<ll, ll> p;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll n, k;
ll arr[101010];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> arr[i];
    sort(arr+1, arr+n+1);
    ll mn = 1, mx = n;
    while(k > 0){
        if(mn == mx) break;
        if(mn <= (n-mx+1) && (arr[mn+1] - arr[mn])*mn <= k){
            k -= (arr[mn+1] - arr[mn])*mn;
            mn++; continue;
        }
        if((n-mx+1) <= mn && (arr[mx] - arr[mx-1])*(n-mx+1) <= k){
            k -= (arr[mx] - arr[mx-1])*(n-mx+1);
            mx--; continue;
        }
        if(mn <= (n-mx+1)){
            ll ans = arr[mx] - arr[mn];
            ans -= k/mn;
            if(ans < 0) cout << 0;
            else cout << ans;
            return 0;
        }else{
            ll ans = arr[mx] - arr[mn];
            ans -= k/(n-mx+1);
            if(ans < 0) cout << 0;
            else cout << ans;
            return 0;
        }
    }
    ll ans = arr[mx] - arr[mn];
    if(ans < 0) cout << 0;
    else cout << ans;
    return 0;
}
