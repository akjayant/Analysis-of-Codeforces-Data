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
typedef pair<ll, ll> p;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
    int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
    int x = 0, y = 0;
    x += a/c; x += !!(a%c);
    y += b/d; y += !!(b%d);
    if(x+y <= k) cout << x << " " << y << "\n";
    else cout << "-1\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}