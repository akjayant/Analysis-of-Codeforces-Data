#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define fst first
#define snd second
#define PI (acos(-1))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define MAXN 1123456
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n) cin >> a[i];

    sort(all(a));reverse(all(a));

    ll ans = 1;
    rep(i,0,n) {
      if (a[i] >= (i+1)) ans=i+1;
    }
    cout<<ans<<endl;
  }
}
