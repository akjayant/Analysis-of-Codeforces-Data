// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░

//PointBlank's code (⌐■_■)
 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define repp(i, a, b) for(ll i = a; i <= b; i++)
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define rrep(i, b, a) for(ll i = b; i >= a; i--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define mem(a, b) memset(a, b, sizeof(a));
#define mem0(a) memset(a, 0, sizeof(a));
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define in_edges(m) repp(i, 1, m){ll a, b; cin >> a >> b; v[a].pb(b), v[b].pb(a);}
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define endl "\n"

const ll MOD = 1000000007;
const ll NICE = 69;

int main() //PointBlank's code ¯\_(ツ)_/¯
{
    quickio
    ll t;
    cin >> t;
    while(t--){
        ll a, b, c;
        ll x, y, z;
        cin >> a >> b >> c;
        x = a, y = b, z = c;
        ll res = 0;
        ll cc = c/2;
        ll pick = min(cc, b);
        b -= pick, c -= pick*2;
        res += pick*3;
        pick = min(a, b/2);
        res += pick*3;
        ll res2 = 0;
        cc = b/2;
        pick = min(cc, x);
        x -= pick, y -= pick*2;
        res2 += pick*3;
        pick = min(y, z/2);
        res2 += pick*3;
        cout << max(res, res2) << endl;
    }
}