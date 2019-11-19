#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define eps 1e-8
#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const ll mod= 1e9+7;
long double PI = acosl(-1);
const ll infl = 1e15;
const int inf = 2e9;
const int nmax = 1e5+10;
const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;




struct Edge{
    int u, v;
    ll w;
    bool operator<(Edge const& other){
        return w < other.w;
    }
};


int par[nmax], rnk[nmax];
int C[nmax], K[nmax];

int faind(int u){
    if(u==par[u]) return u;
    return par[u]=faind(par[u]);
}

void unite(int u, int v){
    u=faind(u), v=faind(v);
    if(u!=v){
        if(rnk[u]<rnk[v]) swap(u,v);
        par[v]=u;
        if(rnk[v]==rnk[u]) rnk[u]++;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);


    int n;
    cin>>n;

    for(int i=1; i<=n; i++) par[i] = i;

    vector<pii>pnt(n);
    for(auto &z : pnt)
        cin>>z.first>>z.second;

    for(int i=1; i<=n; i++) cin>>C[i];
    for(int i=1; i<=n; i++) cin>>K[i];


    vector<Edge>ejes;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int u = i+1, v = j+1;
            int dst = abs(pnt[i].first - pnt[j].first) + abs(pnt[i].second - pnt[j].second);
            Edge e;
            e.u = u, e.v = v, e.w = 1LL * dst * (K[i+1] + K[j+1]);
            ejes.push_back(e);
        }
        Edge e;
        e.u=i+1, e.v=0, e.w = C[i+1];
        ejes.push_back(e);
    }

    sort(ejes.begin(), ejes.end());

    vector<int>sorc;
    vector<pii>conection;
    ll ans=0;

//    cout<<"bal "<<endl;

    for(auto e : ejes){
        int u = e.u, v = e.v;
        ll w = e.w;
        if(faind(u)==faind(v)) continue;
        ans+=w;
//        cout<<w<<" == w "<<endl;
        if(v)
            conection.push_back( {u,v} );
        else
            sorc.push_back(u);
        unite(u,v);
    }

    cout<<ans<<"\n";
    cout<<sorc.size()<<"\n";
    for(int x : sorc) cout<<x<<" ";
    cout<<"\n";
    cout<<conection.size()<<"\n";
    for(pii x : conection) cout<<x.first<<" "<<x.second<<"\n";

}
