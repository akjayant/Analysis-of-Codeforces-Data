#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define ff first
#define ss second
#define maxn 2005
#define pb push_back

using namespace std;
typedef pair<ll, pair<ll, ll> > pii;
priority_queue <pii, vector<pii>, greater<pii> > pq;
map< ll, pair<ll, ll> > mp;
ll k[maxn], c[maxn], l[maxn], r[maxn], visited[maxn];
vector<ll> v;
vector< pair<ll, ll> > edge;


ll dist(ll x, ll y){
    ll res = k[x] + k[y];
    res *= abs(l[x] - l[y] ) + abs(r[x] - r[y]);
    return res;
}


int main()
{
    int n, taken = 0;
    ll res = 0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> l[i] >> r[i];
    }
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }
    for(int i=1;i<=n;i++){
        cin >> k[i];
    }
    for(int i=1;i<=n;i++){
        pq.push({c[i], {i, 0}} );
    }
    while(taken < n){
        auto p = pq.top();
        pq.pop();
        if(visited[p.ss.ff]) continue;
        visited[p.ss.ff] = 1;
        taken ++;
        res += p.ff;
        if(p.ss.ss){
            edge.pb({p.ss.ff, p.ss.ss});
        }
        else{
            v.pb(p.ss.ff);
        }
        ll x = p.ss.ff;
        for(int i=1;i<=n;i++){
            if(visited[i]) continue;
            ll d = dist(x, i);
            pq.push( {d, {i, x} } );
        }
    }
    cout << res << endl;
    cout << v.size() << endl;
    for(auto x: v) cout << x << " "; cout << endl;
    cout << edge.size() << endl;
    for(int i=0;i<edge.size();i++){
        cout << edge[i]. ff << " "<< edge[i].ss<< endl;
    }
    return 0;
}
