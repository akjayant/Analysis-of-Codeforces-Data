#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(ll i = (a); i<= (b); ++i)
#define X first
#define Y second

using namespace std;

const int M=1e5+5;
const ll INF = 1e18;
const ll MOD = 1e9+7;
ll dp[M+5];
string s;
typedef pair<int, int> ii;

struct Canh {
    int u, v;
    ll w;
    Canh(){}
    Canh(int u, int v, ll w):u(u), v(v), w(w){}
    bool operator < (Canh o) {
        return w<o.w;
    }
};

int pr[M];
int _find(int u) {
    if(pr[u] == -1) return u;
    return pr[u] = _find(pr[u]);
}

int n;
typedef pair<ll, ll> II;
II a[M];
ll c[M], k[M];

int main() {
    ios::sync_with_stdio(0);
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i].X>>a[i].Y;
    for(int i=1; i<=n; i++) cin>>c[i];
    for(int i=1; i<=n; i++) cin>>k[i];
    vector<Canh> canh;
    for(int i=1; i<=n; i++) canh.push_back(Canh(0,i,c[i])), pr[i] = -1;
    pr[0] = -1;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            ll w = (k[i]+k[j])*(abs(a[i].X-a[j].X) + abs(a[i].Y-a[j].Y));
            canh.push_back(Canh(i,j,w));
        }
    }

    sort(canh.begin(), canh.end());
    int pu, pv;
    vector<int> ans1;
    vector<ii> ans2;
    ll ans = 0;
    for(Canh c:canh) {
        pu = _find(c.u);
        pv = _find(c.v);
        if(pu != pv) {
            pr[pu] = pv;
            ans += c.w;
            if(c.u == 0) ans1.push_back(c.v);
            else ans2.push_back(make_pair(c.u, c.v));
        }
    }

    sort(ans1.begin(), ans1.end());
    cout<<ans<<"\n";
    cout<<ans1.size()<<"\n";
    for(int x:ans1) cout<<x<<" ";
    cout<<"\n"<<ans2.size()<<"\n";
    for(ii x:ans2) cout<<x.X<<" "<<x.Y<<"\n";
    return 0;
}
