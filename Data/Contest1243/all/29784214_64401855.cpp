// Siddhant Gautam
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long ll
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define bitcount __builtin_popcountll
#define INF 1e18+9
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define FIO ios_base::sync_with_stdio(false)
#define mod 1000000007
ll power(ll a,ll b,ll m)
{
    a%=m;
    ll ret=1;
    while(b)
    {
        if(b&1)
            ret=((ret%m)*(a%m))%m;
        a=((a%m)*(a%m))%m;
        b>>=1;
    }
    return ret;
}

struct DSU{
    ll par[100006];
    ll size[100006];
 
    void init(){
        for(ll i=0;i<100006;i++){
            par[i] = i;
            size[i] = 1;
        }
    }
 
    ll parent(ll n){
        while(n != par[n]){
            n = par[n];
            par[n] = par[par[n]];
        }
        return n;
    }
 
    void add(ll x, ll y){
        ll parx = parent(x);
        ll pary = parent(y);
 
        if(parx == pary) return;
 
        if(size[parx] < size[pary]){
            size[pary] += size[parx];
            par[parx] = pary;
        }
        else{
            size[parx] += size[pary];
            par[pary] = parx;
        }
    }
 
    bool isConnected(ll x,ll y){
        return (parent(x) == parent(y));
    }
}dsu;

int main()
{
    FIO;
    
    int n,m;
    cin >> n >> m;

    vector < int > v[n+3];
    unordered_map < int,int > se[n+3];
    vector < pair < int,int > > arr;

    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
        se[min(x,y)][max(x,y)] = 1;
    }

    for(int i=1;i<=n;i++){
        arr.pb({v[i].size(),i});
    }

    sort(all(arr));
    reverse(all(arr));

    dsu.init();

    int count = 2000000/n + 1;
    int prev = -1;

    for(pair < int,int > p : arr){
        if(count){
            for(int i=1;i<=n;i++){
                if(se[min(p.ss,i)][max(p.ss,i)] == 1){
                    continue;
                }
                dsu.add(p.ss,i);
            }
            count--;
            prev = p.ss;
        }
        else {
            dsu.add(p.ss,prev);
            prev = p.ss;
        }
    }

    set < int > ans;

    for(int i=1;i<=n;i++){
        ans.insert(dsu.parent(i));
    }

    cout << ans.size()-1 << endl;
    return 0;
}