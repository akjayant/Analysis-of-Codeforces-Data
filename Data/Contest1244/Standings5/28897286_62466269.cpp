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

void solve() {
    ll a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    ll one = (ll)ceil((long double)a / (long double)c);
    ll two = (ll)ceil((long double)b / (long double)d);
    if(one + two <= k) 
        cout << one << " " << two << endl;
    else
        cout << -1 << endl;
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
        solve();
    return 0;
}