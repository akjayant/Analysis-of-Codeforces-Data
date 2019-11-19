#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define zoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

ll solve() {
    ll n, i;
    cin >> n;
    string s;
    cin >> s;
    ll ans = n;
    for(i = 0; i < n; i += 1) {
        if(s[i] == '1') {
            ans = (ll)max(ans, 2 * (n - i));
            ans = (ll)max(ans, n + 1);
            break;
        }
    }
    for(i = n - 1; i >= 0; i -= 1) {
        if(s[i] == '1') {
            ans = (ll)max(ans, 2 * (i + 1));
            break;
        }
    }
    return ans;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    zoom;
    ll t;
    cin >> t;
    while(t--)
        cout << solve() << endl;
    return 0;
}