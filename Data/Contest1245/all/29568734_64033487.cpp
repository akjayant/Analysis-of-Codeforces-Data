///not today

#include<bits/stdc++.h>
using namespace std;

#define SZ(x) (int)(x).size()
#define pb push_back
#define ll long long
#define xmax(x, y) (x) = max((x), (y))
#define xmin(x, y) (x) = min((x), (y))
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define int long long
#define pipii pair<int, pair<int, int> >
#define pf push_front

const int maxn = 2005;
vector <int> cmp[maxn], nod_ans;
vector < pll > eg_ans;
vector < pair < ll , pll > > eg;
int e[maxn], cm[maxn], ind[maxn], x[maxn], y[maxn], k[maxn];

void mrg(int a, int b){
    if(a == b)
        return;
    if(SZ(cmp[a]) > SZ(cmp[b]))
        swap(a, b);
    if(e[a] < e[b]){
        e[b] = e[a];
        ind[b] = ind[a];
    }
    for(int i = 0; i < SZ(cmp[a]); i ++){
        int v = cmp[a][i];
        cmp[b].pb(v);
        cm[v] = b;
    }
    cmp[a].clear();
    return;
}

int32_t main(){
    int n;
    cin >>n;
    for(int i = 0; i < n; i ++){
        cin >>x[i] >>y[i];
    }
    for(int i = 0; i < n; i ++){
        cin >>e[i];
        ind[i] = i;
        cm[i] = i;
        cmp[i].pb(i);
    }
    for(int i = 0; i < n; i ++){
        cin >>k[i];
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            int w = (k[i] + k[j])* (abs(x[i] - x[j]) + abs(y[i] - y[j]));
            eg.pb({w, {i, j}});
        }
    }
    int sum = 0;
    sort(eg.begin(), eg.end());
    for(int i = 0; i < SZ(eg); i ++){
        int v = eg[i].S.F, u = eg[i].S.S;
        if(cm[u] != cm[v]){
            if(eg[i].F < max(e[cm[u]], e[cm[v]])){
                mrg(cm[u], cm[v]);
                eg_ans.pb({u, v});
                sum += eg[i].F;
            }
        }
    }
    for(int i = 0; i < n; i ++){
        if(SZ(cmp[i])){
            nod_ans.pb(ind[i]);
            sum += e[i];
        }
    }
    cout <<sum <<endl <<SZ(nod_ans) <<endl;
    for(int i = 0; i < SZ(nod_ans); i ++){
        cout <<nod_ans[i] + 1 <<' ';
    }
    cout <<SZ(eg_ans) <<endl;
    for(int i = 0; i < SZ(eg_ans); i ++){
        cout <<eg_ans[i].F + 1 <<' ' <<eg_ans[i].S + 1 <<' ';
    }
    return false;
}
