#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef pair<pll,pll> ppll;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fst first
#define snd second
#define ins insert
#define pb push_back

const int N = 2005;
const int MOD = 1e9 + 7;

vector<pll> a;
ll c[N],k[N];
priority_queue<plll,vector<plll>,greater<plll> > qu;
bool used[N];
ll ans = 0;
vector<int> st;
vector<pll> ed;
ll get(ll x,ll y){
    ll dist = abs(a[x].fst - a[y].fst) + abs(a[x].snd - a[y].snd);
    return dist * (k[x] + k[y]);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0;i < n; ++i){
        cin >> a[i].fst >> a[i].snd;
    }
    for(int i = 0;i < n; ++i){
        cin >> c[i];
        qu.push({c[i],{i,i}});
    }
    for(int i = 0;i < n; ++i){
        cin >> k[i];
    }
    while(!qu.empty()){
        ll u = qu.top().snd.fst,v = qu.top().snd.snd,dst = qu.top().fst;
        qu.pop();
        if(used[v])continue;
        used[v] = true;
        ans += dst;
        if(u == v){
            st.pb(u);
        }else{
            ed.pb({u,v});
        }
        for(int i = 0;i < n; ++i){
            if(!used[i]){
                qu.push({get(v,i),{v,i}});
            }
        }
    }
    cout << ans << "\n";
    cout << st.size() << "\n";
    for(auto &it : st)cout << it + 1 << " ";
    cout << "\n";
    cout << ed.size() << "\n";
    for(auto &it : ed)cout << it.fst + 1 << " " << it.snd + 1 << "\n";
    return 0;
}
