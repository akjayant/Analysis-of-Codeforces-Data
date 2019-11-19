#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<stack>
#include<algorithm>
#include<string>
#include<string.h>
#include<assert.h>
#include<iomanip>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll fpb(ll a, ll b){
    if(b == 0)return a;
    return fpb(b, a % b);
}

const int N = 2005;

int dsu[N];
int find(int x){
    if(dsu[x] == x)return x;
    return dsu[x] = find(dsu[x]);
}

bool merge(int a, int b){
    a = find(a), b = find(b);
    if(a == b)return false;
    dsu[a] = b;
    return true;
}

struct edge{
    ll u, v, c;
};

bool cmp(edge a, edge b){
    return a.c < b.c;
}

int x[N], y[N], c[N], k[N];

ll dist(int i, int j){
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
    for(int i = 1; i <= n; ++i) cin >> c[i];
    for(int i = 1; i <= n; ++i) cin >> k[i];
    
    for(int i = 0; i <= n; ++i) dsu[i] = i;

    vector<edge> lst;
    lst.pb({0, 1, c[1]});
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j < i; ++j){
            ll cst = (k[i] + k[j]) * dist(i, j);
            lst.pb({j, i, cst});
        }
        lst.pb({0, i, c[i]});
    }

    sort(lst.begin(), lst.end(), cmp);

    vector<int> elect;
    vector<ii> conn;
    ll res = 0;
    for(int i = 0; i < lst.size(); ++i){
        if(merge(lst[i].u, lst[i].v)){
            if(lst[i].u == 0){
                elect.pb(lst[i].v);
            }else{
                conn.pb({lst[i].u, lst[i].v});
            }
            res += lst[i].c;
        }
    }

    cout << res << endl;
    
    cout << elect.size() << endl;
    for(int i = 0; i < elect.size(); ++i){
        if(i)cout << " ";
        cout << elect[i];
    }cout << endl;

    cout << conn.size() << endl;
    for(int i = 0; i < conn.size(); ++i){
        cout << conn[i].F << " " << conn[i].S << endl;;
    }
    
}