/*
When you walk through a storm
Hold your head up high
And don't be afraid of the dark
At the end of the storm
There's a golden sky
And the sweet silver song
of the lark
Walk on, through the wind
Walk on, through the rain
Though your dreams be tossed
and blown
Walk on, walk on
With hope in your heart
And you'll never walk alone
YNWA
*/
 
//hell_hacker
//IT TAKES EVERYTHING and IT IS NOT LUCK
//PICK ME LAST -- COME OUT OF N^WHERE
//WHY NOT?
 
/*
And you came my way on a winner's day
Shouted loudly come out and play
Can't you tell I got news for you
Sun is shining and so are you
*/
 
// author: SweetPrinces
 
/*
 
___▒▒▒▒______▒▒▒▒▒▒▒▒
__▒▒░░░░▒▒▒▒▒▒▒░░░░▒▒
_▒▒░░░░░░▒▒▒▒▒░░░__░▒▒
▒▒░___░░▒▒▒▒▒▒▒░░__░▒▒
▒▒░__░▒▒▒▒▒▒▒▒▒▒▒_░▒
_▒░░▒▒▒▒▒▒█▒▒▒▒▒█▒▒
___▒▒▒▒▒▒░██▒▒▒▒██_▒___▒▒___▒▒
___▒▒▒▒▒░░░░███░░░▒▒___▒▒__▒▒
___▒▒▒▒▒░░___███____▒▒___▒▒_▒▒
____▒▒░░__▀▄▄▄▄▄▄▀░▒_____▒▒▒▒▒
_____▒▒▒░_____▀▀_░▒▒______▒▒▒▒▒▒
___▒▒▒░▒░░░▒▒▒░_▒▒▒▒▒▒▒▒▒▒▒
__▒▒▒░▒▒▒▒▒░░░▒░▒▒▒▒▒▒▒▒▒
_▒▒▒░▒▒▒▒___▒▒__▒▒▒▒▒▒▒▒▒
_▒▒▒░▒░░_________░▒▒▒▒
 
*/
 
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ll                  long long
#define ull                 unsigned long long
#define ld                  long double
#define f                   first
#define se                  second
#define SpeedForce          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sqr(x)              ((x)*(x))
#define forn(i, n)          for(ll i=0;i<n;++i)
#define forl(i, a, b)       for(ll i=(a);i<=(b);++i)
#define ford(i, a, b)       for(int i=(a);i>=(b);--i)
#define forg(i, a, b, c)    for(ll i=(a);i<=(b);i += (c))
#define cno                 cout<<"NO";return 0;
#define cye                 cout<<"YES";return 0;
#define pb                  push_back
#define mp                  make_pair
#define fbo                 find_by_order
#define ofk                 order_of_key
#define all(a)              (a).begin(), (a).end()
#define pb1                 pop_back
#define sz(x)               ((int)(x).size())
#define fill(a, x)          memset(a, x, sizeof(a))
#define debug(v)            makeDebugInfo(#v, v)
#define dbg(v)              out.put(makeDebugInfo(#v, v)), cout.flush()
#define _read(x)            freopen(x, "r", stdin)
#define _write(x)           freopen(x, "w", stdout)
#define files(x)            _read(x ".in"); _write(x ".out")
 
typedef pair < int, int > pii;
typedef pair < char, int > pci;
typedef pair < pii, int > ppii;
typedef pair < ll, ll > pll;
typedef pair < ull, ull > puu;
typedef pair < int, string > pis;
typedef pair < string, int > psi;
typedef map < int, int > mii;
typedef map < int, int > mii;
typedef map < int, char > mic;
typedef map < string, int > msi;
typedef map < string, string > mss;
typedef map < char, int > mci;
typedef map < char, ll > mcl;
typedef map < ll, ll > mll;
typedef map < pii, int > mpii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < char > vc;
typedef vector < ll > vll;
typedef vector < pii > vpii;
typedef vector < pll > vpll;
typedef vector < pis > vpis;
typedef map < int, vpii > mivpi;
typedef set < int > si;
typedef set < char > sc;
typedef set < ll > sll;
typedef set< pair < ull, ull > > spuu;
typedef set< pii > spii;
typedef priority_queue< ll > pqll;
 
const int N = 50;
const int M = 60;
const int MAXK = 1e5+3;
const int Candy = 1e6+3;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const ll INF = 1e18;
const double PI = 3.1415926535897932384626433;
const ld EPS = 1e-12;
 
 
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
 
char getChar() { char c = 0; while (c <= ' ') cin >> c; return c; }
 
inline ll fast_pow(ll a, ll b){
	ll res = a, ret = 1;
	while(b>0){
		if(b%2)
			ret = (ret*res)%mod;
		res = (res*res)%mod;
		b/=2;
	}
	return ret;
}
 
inline ll fact(ll n){
    int f = 1;
    forl(i, 2, n) f = f * i % mod;
    return f;
}
 
inline ll Cnk(ll n, ll r){
    r = min(r, n - r);
    ll ans = 1;
    ford(i, n, n - r + 1) ans = (ans * i) % mod;
    forl(i, 1, r) ans = (ans * fast_pow(i, mod - 2)) % mod;
    return ans;
}

int k, n, a[30];
string s, t;

int main(){
    SpeedForce
    cin >> k;
    while(k--){
        cin >> n;
        cin >> s >> t;
        vi g;
        forn(i, n){
            if(s[i] != t[i]){
                a[s[i] - '0']++;
                a[t[i] - '0']++;
                g.push_back(i);
			}
		}
		bool ok = 0;
		forn(i, 26){
		    if(a[i] & 1){
		        ok = 1;
		    }
		}
		if(ok){
		    cout << "NO\n";
		    continue;
		}
		int m = sz(g);
		vector <pii> v;
		bool flag = 0;
		forn(i, m){
            if(s[g[i]] == t[g[i]]) continue;
            ok = 0;
            forl(j, i + 1, m - 1){
                if(t[g[i]] == t[g[j]]){
                    v.pb({g[i], g[j]});
                    swap(s[g[i]], t[g[j]]);
                    ok = 1;
                    break;
                }
            }
            if(ok) continue;
            forl(j, i + 1, m - 1){
                if(t[g[i]] == s[g[j]]){
                    v.pb({g[j], g[j]});
                    swap(s[g[j]], t[g[j]]);
                    v.pb({g[i], g[j]});
                    swap(s[g[i]], t[g[j]]);
                    ok = 1;
                    break;
                }
            }
            if(!ok){
               cout << "NO\n";
               flag = 1;
               break;
            }
		}
		if(flag) continue;
		cout << "YES\n";
		cout << sz(v) << endl;
		forn(i, sz(v)){
		    cout << v[i].f + 1 << ' ' << v[i].se + 1 << '\n';
		}
    }
    return (!false && !true) || ((ll)((ll)(1713 + 2377 + 1464) * (ll)(1713 + 2377 + 1464) * (ll)(1713 + 2377 + 1464)) != (ll)(171323771464));
}