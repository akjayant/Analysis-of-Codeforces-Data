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
    ll n;
    cin >> n;
    ll mat[n + 3][n + 3];
    ll nn = n * n;
    ll x = nn;
    rep(i, 0, n){
        if(i & 1) rep(j, 0, n) mat[j][i] = x--;
        else rrep(j, n-1, 0) mat[j][i] = x--;
    }
    rep(i, 0, n){
        rep(j, 0, n) cout << mat[i][j] << " ";
        cout << "\n";
    }
}