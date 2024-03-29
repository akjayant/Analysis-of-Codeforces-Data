#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,pll> ppll;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fst first
#define snd second
#define ins insert
#define pb push_back

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int a,b;
    cin >> a >> b;
    if(__gcd(a,b) != 1)cout << "Infinite";else cout << "Finite";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 0;i < t; ++i){
        solve();
        cout << "\n";
    }
    return 0;
}
