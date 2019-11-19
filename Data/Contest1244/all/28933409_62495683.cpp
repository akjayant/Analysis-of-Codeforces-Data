#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , ll >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
const int N=1e5+100;

vector <int> g[N];
vector <int> c;
ll val[N][3];
ll ans1[N];
ll dfs(ll v,ll p){
    c.pb(v);
    for (int i=0;i<g[v].size();i++){
        ll u=g[v][i];
        if (u==p){
            continue;
        }

        dfs(u,v);

    }


}
int32_t main(){
    sync;
    ll n,p,w,d;
    cin >> n >> p >> w >> d;

    /// halat aval

    for (int i=0;i<d+1;i++){
        ll z=p-i*w;
        if (z%d!=0 || z<0){
            continue;
        }
        ll o=z/d;
        if (o+i<=n){
            cout << i << endl;
            cout << o << endl;
            cout << n-i-o << endl;
            return 0;
        }

    }

    for (int i=0;i<w+1;i++){
        ll z=p-i*d;
        if (z%w!=0 || z<0){
            continue;
        }
        ll o=z/w;
        if (o+i<=n){
            cout << o << endl;
            cout << i << endl;
            cout << n-i-o << endl;
            return 0;
        }
    }
    cout << -1;

}



















