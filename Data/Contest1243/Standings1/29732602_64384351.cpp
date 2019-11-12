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

  int k;
  cin >> k;

  while (k--) {
    int n;
    cin >> n;

    vi cnt(26);
    string s, t;
    cin >> s >> t;

    trav(c,s)cnt[c-'a']++;
    trav(c,t)cnt[c-'a']++;

    bool bad=false;
    rep(i,0,26) {
      if (cnt[i]&1) {
        cout << "No" << endl;
        bad=true;
        break;
      }
    }
    if(bad)continue;

    vi diffs;
    rep(i,0,n) {
      if (s[i] != t[i]) diffs.pb(i);
    }

    bool ok = true;
    ok &= sz(diffs) <= 2;

    if (sz(diffs) == 2) {
      int i = diffs[0], j = diffs[1];
      ok &= (s[i] == s[j] or t[j] == t[i]);
    }

    cout <<( ok ? "Yes" : "No" )<< endl;

  }
}
