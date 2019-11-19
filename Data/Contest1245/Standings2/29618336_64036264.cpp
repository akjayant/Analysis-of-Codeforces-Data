#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
#define pii pair<ll, ll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
 
const int N = 1e5 + 5;
const ll mod = 2e18+7;
const ll INF = (ll)8e18 + 5;

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

vector<pii> g[N];
vector<int> par(N);

ll dijkstra(int src, const int n){
    vector<ll> dist(N, INF);
    dist[src] = 0;
    dist[0] = 0;
    set<pii> s;
    ll total = 0;
    for(int j = 1; j <= n; j++)
        s.insert({dist[j], j});
    while(!s.empty()){
        int v = s.begin() -> S;
        total += dist[v] - dist[par[v]];
        s.erase(s.begin());
        for(auto i : g[v]){
            ll u = i.F, cur = i.S;
            if(dist[u] > (dist[v] + cur)){
                s.erase({dist[u], u});
                par[u] = v;
                dist[u] = dist[v] + cur;
                s.insert({dist[u], u});
            }
        }
    }
    return total;
}

ll dp[2][2][2][2][31];
string lft, rgt;

ll foo(int f11, int f12, int f21, int f22, int pos){
    if(pos < 0) return 1;
    ll &ans = dp[f11][f12][f21][f22][pos];
    if(ans == -1){
        ans = 0;
        // 1 0
        int lss_r1 = (f12 == 0 || (rgt[pos] == '1'));
        int grt_l2 = (f21 == 0 || (lft[pos] == '0'));

        int n_f11 = (f11 && lft[pos] == '1')? 1 : 0;
        int n_f12 = (f12 && rgt[pos] == '1')? 1 : 0;
        int n_f21 = (f21 && lft[pos] == '0')? 1 : 0;
        int n_f22 = (f22 && rgt[pos] == '0')? 1 : 0;

        // cout << pos << " " << grt_l2 << " " << lss_r1 << endl;
        if(grt_l2 && lss_r1){
            // cout << pos << " --> 1 0" << endl; 
            ans = (ans + foo(n_f11, n_f12, n_f21, n_f22, pos-1)) % mod;
        }
        // 0 1
        int grt_l1 = (f11 == 0 || lft[pos] == '0');
        int lss_r2 = (f22 == 0 || rgt[pos] == '1');

        // cout << pos << ": " << f11 << " " << f12 << " " << f21 << " " << f22 << " -> " << grt_l1 << " " << lss_r2 << endl;
        n_f11 = (f11 && lft[pos] == '0')? 1 : 0;
        n_f12 = (f12 && rgt[pos] == '0')? 1 : 0;
        n_f21 = (f21 && lft[pos] == '1')? 1 : 0;
        n_f22 = (f22 && rgt[pos] == '1')? 1 : 0;

        if(grt_l1 && lss_r2){
            // cout << pos << " --> 0 1" << endl; 
            ans = (ans + foo(n_f11, n_f12, n_f21, n_f22, pos-1)) % mod;
        }
        // 0 0

        grt_l1 = (f11 == 0 || lft[pos] == '0');
        grt_l2 = (f21 == 0 || lft[pos] == '0');

        n_f11 = (f11 && lft[pos] == '0')? 1 : 0;
        n_f12 = (f12 && rgt[pos] == '0')? 1 : 0;
        n_f21 = (f21 && lft[pos] == '0')? 1 : 0;
        n_f22 = (f22 && rgt[pos] == '0')? 1 : 0;

        if(grt_l1 && grt_l2) {
            // cout << pos << " --> 0 0" << endl; 
            ans = (ans + foo(n_f11, n_f12, n_f21, n_f22, pos-1)) % mod;
        }
    }
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        lft = rgt = "";
        for(int j = 30; j >= 0; j--){
            if((1LL << j)&l) lft += '1';
            else lft += '0';

            if((1LL << j)&r) rgt += '1';
            else rgt += '0';
        }
        reverse(lft.begin(), lft.end());
        reverse(rgt.begin(), rgt.end());
        // // cout << lft << " " << rgt << endl;
        memset(dp, -1, sizeof(dp));
        cout << (foo(1, 1, 1, 1, 30)) % mod << '\n';
    }
    return 0;
}
