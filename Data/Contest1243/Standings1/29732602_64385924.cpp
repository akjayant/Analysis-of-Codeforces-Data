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

    cout << "Yes" << endl;
    
    vii swaps;
    rep(i,0,n) {
      //cerr << s << " " << t << endl;
      if (s[i] == t[i]) continue;

      bool good=false;
      rep(j,i+1,n) if (t[j] == t[i]) {
        swap(s[i], t[j]);
        swaps.pb({i, j});
        good=true;
        break;
      }

      if (good)continue;
      rep(j,i+1,n) if (s[j] == s[i]) {
        swap(s[j], t[i]);
        swaps.pb({j, i});
        good=true;
        break;
      }
      if (good)continue;

      rep(j,i+1,n) {
        if (s[j] == t[i]) {
          swap(s[j], t[i+1]);
          swap(s[i], t[i+1]);
          swaps.pb({j,i+1});
          swaps.pb({i,i+1});
          good=true;
          break;
        }
      }

      if (good)continue;
      rep(j,i+1,n) {
        if (t[j] == s[i]) {
          swap(s[i+1], t[j]);
          swap(t[i], s[i+1]);
          swaps.pb({i+1,j});
          swaps.pb({i+1,i});
          good=true;
          break;
        }
      }

    }
    cout << sz(swaps) << endl;
  trav(k,swaps) cout << k.fst+1 << " " << k.snd+1 << endl;
  }

}
