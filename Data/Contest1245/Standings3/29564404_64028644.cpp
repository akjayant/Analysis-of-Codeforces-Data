#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define mp make_pair
#define ms(v,x) memset(v,x,sizeof(v))
#define pii pair<int,int>
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define td(v) v.begin(),v.end()
#define inf 1000000000 // 1e9
#define M   1000000007 // 1e9 + 7
using namespace std;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
int exp(int a,int b,int m){
    if(b==0) return 1LL;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}
vector<pii> v;
vector<int> c,k;
vector<int> pw;
class DisjointSet{ public:
    vector<int> parent;
    vector<int> sz;
    DisjointSet(int n): parent(n), sz(n) { for(int i=0; i<n; i++) parent[i] = i,sz[i] = 1; }
    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
    int find(int a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }
    bool same_set(int a, int b){ return find(a) == find(b); }
};
int mh(pii a,pii b){
    return abs(a.ff - b.ff) + abs(a.ss - b.ss);
}
struct edge{
    int a,b,c;
    bool operator<(const edge &y) const{
        return (c < y.c);
    }
};
vector<int> pai(2020);
vector<int> cst(2020);
int find_set(int v) {
    if (v == pai[v])
        return v;
    return pai[v] = find_set(pai[v]);
}
void make_set(int v) {
    pai[v] = v;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (cst[a] > cst[b])
            swap(a, b);
        pai[b] = a;
    }
}
main(){
    fastio;
    int n;
    cin >> n;
    v.resize(n);
    c.resize(n);
    k.resize(n);
    pw.assign(n,1);
    for(pii &x : v) cin >> x.ff >> x.ss;
    int ans = 0;
    for(int &x : c){
        cin >> x;
        ans += x;
    }
    vector<edge> e(n);
    DisjointSet dsu(n);
    for(int &x : k) cin >> x;  
    for(int i=0;i<n;i++){
        cst[i] = c[i];
        pai[i] = i;
        for(int j=i+1;j<n;j++){
            e.pb({i, j, (k[i] + k[j]) * mh(v[i],v[j])} );
        }
    }
    sort(td(e));
    vector<edge> mst;
    for(int i=0;i<e.size();i++){
        if(!dsu.same_set(e[i].a,e[i].b)){
            dsu.join(e[i].a,e[i].b);
            mst.pb(e[i]);
        }
    }
    vector<pii> cn;
    for(int i=0;i<mst.size();i++){
        int a = mst[i].a, b = mst[i].b, c = mst[i].c;
        int w = max(cst[find_set(a)],cst[find_set(b)]);
        if((k[a] + k[b]) * mh(v[a],v[b]) < w){
            if(w==cst[find_set(a)]){
                pw[find_set(a)] = 0;
            }
            else pw[find_set(b)] = 0;
            union_sets(a,b);
            ans += (k[a] + k[b]) * mh(v[a],v[b]) - w;
            cn.pb({a,b});
        }
    }
    cout << ans << endl;
    cout << accumulate(td(pw),0) << endl;
    for(int i=0;i<n;i++){
        if(pw[i]) cout << i+1 << " ";
    }
    cout << endl;
    cout << cn.size() << endl;
    for(pii &x : cn){
        cout << x.ff+1 << " " << x.ss+1 << endl;
    }
}