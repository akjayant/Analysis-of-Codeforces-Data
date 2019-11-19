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

int arr[1010];

void solve(){
    int cnt = 0;
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for(int i=1; i<=n; i++){
        arr[i] = s[i-1] == '1';
        cnt += arr[i];
    }
    ans = n;
    for(int i=1; i<=n; i++){
        if(arr[i]){
            ans = max(ans, i+i);
            int t = n-i+1;
            ans = max(ans, t+t);
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}