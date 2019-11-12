#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
#define pii pair<int, int>
#define F first
#define S second
#define pb push_back
#define mp make_pair
 
const int N = 2e5 + 5;
const int mod = 1e9+7;
const ll INF = (ll)4e18 + 5;

inline int mul(int a, int b){
    return ((ll)a * b) % mod;
}

inline int add(int a, int b){
    int ans = a + b;
    if(ans >= mod) ans -= mod;
    return ans; 
}

// credits : codeforces :https://codeforces.com/blog/entry/54396
bool isprime(ll n){
    if(n<2) return false;
    for(ll i=2;i*i*i<=n;++i) if(n%i==0) return false;
    for(int it=0;it<1e2;++it){
        ll i = rand()%(n-1)+1;
        if(__gcd(i,n)!=1) return false;
        // if(mpow(i,n-1,n)!=1) return false;
    }
    return true;
}

ll fast_pow(ll a, ll b){
    ll ans = 1;
    a %= mod;
    while(b){
        if(b&1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

struct seg_tree{
    vector<ll> seg;
    vector<ll> lzy;
    int n;

    seg_tree(int x) : n(x){
        seg.resize(4*n+5);
        lzy.resize(4*n+5);
    } 

    void update_lzy(int l, int r, int i){
        if(!lzy[i]) return;
        seg[i] += lzy[i];
        if(l != r) lzy[i*2+1] += lzy[i], lzy[i*2+2] += lzy[i];
        lzy[i] = 0;
    }

    void update(int x, int y, ll val, int l = 0, int r = -1, int i = 0){
        if(r == -1) r += n;
        update_lzy(l, r, i);
        if(r < x || l > y) return; 
        if(l >= x && r <= y){
            lzy[i] += val;
            return update_lzy(l, r, i);
        }
        int m = (l+r) >> 1;
        update(x, y, val, l, m, i*2+1);
        update(x, y, val, m+1, r, i*2+2);
        seg[i] = min(seg[i*2+1], seg[i*2+2]);
    }

    ll query(int x, int y, int l = 0, int r = -1, int i = 0){
        if(r == -1) r += n;
        update_lzy(l, r, i);
        if(r < x || l > y) return INF;
        if(l >= x && r <= y) return seg[i];
        int m = (l+r) >> 1;
        ll ans = min(query(x, y, l, m, i*2+1), query(x, y, m+1, r, i*2+2));
        return ans;
    }
};

vector<int> g[N];

struct DSU{
    vector<int> sz, p;

    DSU(int n){
        sz.resize(n+1, 1);
        p.resize(n+1, 0);
        for(int j = 1; j <= n; j++) p[j] = j;
    }

    int par(int x){
        return (p[x] == x)? x : p[x] = par(p[x]);
    }

    void merge(int u, int v){
        // cout << "merge: " << u << " " << v << endl;
        u = par(u);
        v = par(v);
        if(sz[u] > sz[v]) swap(sz[u], sz[v]);
        sz[v] += sz[u];
        p[u] = v;
    }
};

void explore(int v, DSU& dsu, const int n){
    vector<int> present(n+1, 0);
    for(auto i : g[v]) present[i] = 1;
    for(int j = 1; j <= n; j++)
        if(!present[j]) dsu.merge(v, j);
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        
        int fg = 1;
        vector<int> cnt(26);
        for(auto i : s1) cnt[i - 'a'] ++;
        for(auto i : s2) cnt[i - 'a'] ++;
        for(int j = 0; j < 26; j++)
            if(cnt[j] % 2) fg = 0;

        if(!fg){
            cout << "No\n";
            continue;
        }
        // map< pair<char, char>, vector<int> > s;
        // for(int j = 0; j < n; j++)
        //     if(s1[j] != s2[j]) s[{s1[j], s2[j]}].pb(j);

        int steps = 0;
        vector<pii> ans;
        vector< pair<char, char> > lft;
        vector<int> pos;

        for(int j = 0; j < n; j++)
            if(s1[j] != s2[j]) lft.pb({s1[j], s2[j]}), pos.pb(j);

        // for(auto i : s){
        //     int n = i.S.size();
        //     if(n % 2) lft.pb(i.F), pos.pb(i.S.back()), n--;
        //     for(int j = 0; j < n; j+=2)
        //         ans.pb({i.S[j], i.S[j+1]}), steps ++;
        // }

        #define pcc pair<char, char>
        while(!lft.empty()){
            pcc st = lft.back();
            if(st.F == st.S){
                lft.pop_back();
                pos.pop_back();
                continue;
            }

            int up = -1;
            for(int j = 0; j < (int)lft.size() - 1; j++)
                if(st.F == lft[j].F){
                    up = j;
                    break;
                }

            if(up != -1){
                lft[up].F = st.S;
                ans.pb({pos[up], pos.back()});
                steps ++;
                lft.pop_back();
                pos.pop_back();
                continue;
            }

            for(int j = 0; j < (int)lft.size() - 1; j++)
                if(st.F == lft[j].S){
                    up = j;
                    break;
                }

            // cout << up << endl;
            ans.pb({pos.back(), pos.back()});
            ans.pb({pos.back(), pos[up]});
            steps += 2;
            lft[up].S = st.S;
            lft.pop_back();
            pos.pop_back();
        }
        
        if(steps > 2*n) fg = 0;
        if(fg){
            cout << "Yes\n";
            cout << steps << '\n';
            for(auto i : ans) cout << i.F+1 << " " << i.S+1 << '\n';
        }
        else cout << "No\n";
    }
    return 0;
}
