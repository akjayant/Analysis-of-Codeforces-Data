#include<bits/stdc++.h>
using namespace std;
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/*template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
*/typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pl;
typedef pair<int,int> pii;

#define int ll
#define LOCAL 0
#define dbg(x) cout << #x << " is " << x << "\n"
#define gll(x) scanf("%d",&x)
#define gll2(x,y) scanf("%d%d",&x,&y)
#define gll3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gllarr(arr,n) f(i,n) gll(arr[i]);
#define sz(x) ((int)x.size())
#define s(x) sort(x.begin(),x.end())
#define all(v) v.begin(),v.end()
#define rs(v) { s(v) ; r(v) ; }
#define r(v) {reverse(all(v));}
#define pb push_back
#define f(i,n) for(int i=0;i<n;i++)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)

const ll mod = (ll)1e9 + 7;
const ll inf = (ll)1e16;
const ld eps = 1e-12;
const ll N = (int)1e5 + 5;
const ll LOGN = 19;
const ld PI = 3.14159265358979323846;
inline ll mul(ll a, ll b, ll m = mod) { return (ll)(a * b) % m;}
inline ll add(ll a, ll b, ll m = mod) { a += b; if(a >= m) a -= m; if(a < 0) a += m; return a;}
inline ll power(ll a, ll b, ll m = mod) { if(b == 0) return 1; if(b == 1) return (a % m); ll x = power(a, b / 2, m); x = mul(x, x, m); if(b % 2) x = mul(x, a, m); return x;}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (LOCAL) {
        freopen("C:\\Users\\Dishant\\Desktop\\Collection-DEV c++\\input.txt", "r", stdin);
        freopen("C:\\Users\\Dishant\\Desktop\\Collection-DEV c++\\output.txt", "w", stdout);
    }
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s, t;
        cin>>s>>t;
        int f[26] = {0};
        f(i, n) {
            f[s[i] - 'a']++;
            f[t[i] - 'a']++;    
        }
        bool ok = true;
        f(i, 26) {
            if(f[i] & 1) {
                ok = false;
                break;
            }
        }
        if(!ok) {
            cout<<"No\n";
            continue;
        }
        set<int> s_set[26], t_set[26];
        f(i, n) {
            s_set[s[i] - 'a'].insert(i);
            t_set[t[i] - 'a'].insert(i);
        }
        vector< pair<int, int> > ans;
        f(i, n) {
            if(s[i] == t[i]) {
                int to = s[i] - 'a';
                s_set[to].erase(s_set[to].find(i));
                t_set[to].erase(t_set[to].find(i));
                continue;
            }
            int to = s[i] - 'a';
            s_set[to].erase(s_set[to].find(i));
            if(!s_set[to].empty()) {
                int prev_t = t[i] - 'a';
                int pos = *s_set[to].begin();
                s_set[to].erase(s_set[to].begin());
                t_set[prev_t].erase(t_set[prev_t].find(i));
                s_set[prev_t].insert(pos);
                swap(t[i], s[pos]);
                ans.pb({pos, i});
            }
            else {
                int pos = *t_set[to].begin();
                int prev_s = s[pos] - 'a';
                s_set[prev_s].erase(s_set[prev_s].find(pos));
                t_set[to].erase(t_set[to].find(pos));
                s_set[to].insert(pos);
                t_set[prev_s].insert(pos);
                swap(t[pos], s[pos]);
                ans.pb({pos, pos});
                
                int prev_t = t[i] - 'a';
                s_set[to].erase(s_set[to].find(pos));
                t_set[prev_t].erase(t_set[prev_t].find(i));
                s_set[prev_t].insert(pos);
                swap(t[i], s[pos]);
                ans.pb({pos, i});
            }
            assert(t[i] == s[i]);
        }
        assert(sz(ans) <= 2 * n);
        cout<<"Yes\n";
        cout<<ans.size()<<"\n";
        for(auto&it: ans) cout<<it.first + 1<<' '<<it.second + 1<<"\n";
    }
    return 0;
}