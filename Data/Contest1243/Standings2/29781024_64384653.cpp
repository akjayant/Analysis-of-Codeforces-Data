#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repb(i, n) for(ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define reprb(i, a, b) for(ll i = (b)-1; i >= (a); i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
const ld EPS = 1e-12L;
const ld PI = 3.1415926535897932385L;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(ull x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class S, class T>inline bool chmax(S &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class S, class T>inline bool chmin(S &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

void Pr(bool f){
    cout << (f ? "Yes" : "No") << "\n";
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll Q;
    cin >> Q;
    rep(qi, Q){
        ll n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        if(s == t){
            Pr(1);
            continue;
        }
        vll cnt(26, 0);
        rep(i, n){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']++;
        }
        bool f = 1;
        rep(i, 26){
            if(cnt[i] % 2 == 1){
                f = 0;
                break;
            }
        }
        Pr(f);
        if(!f) continue;
        vp ans;
        rep(i, n-1){
            if(s[i] == t[i]) continue;
            repr(j, i+1, n){
                if(s[j] == s[i]){
                    ans.emplace_back(j+1, i+1);
                    swap(s[j], t[i]);
                    goto cont;
                }
            }
            repr(j, i+1, n){
                if(t[j] == s[i]){
                    ans.emplace_back(j+1, j+1);
                    ans.emplace_back(j+1, i+1);
                    swap(s[j], t[j]);
                    swap(s[j], t[i]);
                    goto cont;
                }
            }
            cont:;
        }
        cout << SZ(ans) << "\n";
        rep(i, SZ(ans)){
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
    return 0;
}