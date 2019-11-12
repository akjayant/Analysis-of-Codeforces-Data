
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sz size()
#define cnt continue
#define fr(i, l, r) for(int i = l; i <= r; ++ i)
#define rf(i, r, l) for(int i = r; i >= l; -- i)

#pragma GCC optimize(-O3)
#pragma GCC optimize(Ofast)
#pragma GCC optimize("unroll-loops")

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef vector <pii> vpi;
typedef vector <pll> vpl;

mt19937_64 rnd(time(NULL));

const ll I = 1e18 + 10;
const ll N = 2e6 + 10;
const ll M = 1e9 + 7;
const ll oo = 1e18;

ll u[N], p[N], ans, now;
ll n, m, x, y;
set <ll> s;
vl dfsO;
vpl e;
vl g[N], cnm[N];

void dfs(ll x){
    if(u[x])return;
    dfsO.pb(x);
    u[x] = 1;
    fr(i, 1, g[x].sz - 1){
        ll l = g[x][i - 1], r = g[x][i];
        while(s.sz){
            auto it = s.upper_bound(l);
            if(it != s.end() && *it < r){
                s.erase(it);
                dfs(*it);
            }
            else break;
        }
    }
}

void _mrg(ll x, ll y){
    if(p[x] == p[y])return;
    ans ++;
    ll px = p[x], py = p[y];
    if(cnm[px] > cnm[py])swap(px, py);
    for(auto i : cnm[px]){
        p[i] = py;
        cnm[py].pb(i);
    }
    cnm[px].clear();;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll T, n;
    string s, t;
    vpl ans;

    cin >> T;
    while(T --){
        ans.clear();
        cin >> n >> s >> t;
        s = "+" + s;
        t = "+" + t;
        fr(i, 1, n){
            if(s[i] != t[i]){
                ll f = 0;
                fr(j, i + 1, n){
                    if(s[j] == t[j])cnt;
                    if(t[j] == t[i]){
                        ans.pb({i, j});
                        swap(s[i], t[j]);
                        f = 1;
                        break;
                    }
                }
                if(f == 1)cnt;
                fr(j, i + 1, n){
                    if(s[j] == t[j])cnt;
                    if(s[j] == t[i]){
                        ans.pb({j, j});
                        swap(s[j], t[j]);
                        ans.pb({i, j});
                        swap(s[i], t[j]);
                        f = 1;
                        break;
                    }
                }
            }
        }
        if(s == t){
            cout << "Yes\n";
            cout << ans.sz << "\n";
            for(auto i : ans)cout << i.ft << ' ' << i.sd << "\n";
        }   else{
            cout << "No\n";
        }
    }
    return 0;
}

/*
4 2
1 2 10 11
*/
