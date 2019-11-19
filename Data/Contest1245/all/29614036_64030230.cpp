#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pt complex<double>
#define ft first
#define sc second
using namespace std;

ll peso[2005];
vector< pair<ll, pii> > w;
int ds[2005];
vll c, k;

int ini(int n){
    for(int i=0;i<n;i++){
        ds[i] = i;
        peso[i] = i;
    }
}

int fin(int x){
    if(ds[x] == x)return x;
    return ds[x] = fin(ds[x]);
}

ll unir(int x, int y, ll weight){
    ll res = weight;
    x = fin(x);
    y = fin(y);
    if(x != y){
        res -= c[peso[x]] + c[peso[y]] - min(c[peso[x]], c[peso[y]]);
        if(res <= 0){
            ds[x] = y;
            if(c[peso[x]] < c[peso[y]]) peso[y] = peso[x];
            return res;
        }
    }
    return 1;
}

int main(){
    int i,j,n,x,y,aux;
    ll tot = 0;
    cin>>n;
    vector<pii> v;
    for(i=0;i<n;i++){
        cin>>x>>y;
        v.pb({x, y});
    }
    for(i=0;i<n;i++){
        cin>>aux;
        tot += aux;
        c.pb(aux);
    }
    for(i=0;i<n;i++){
        cin>>aux;
        k.pb(aux);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            w.pb({(abs(v[i].ft - v[j].ft) + abs(v[i].sc - v[j].sc)) * (k[i] + k[j]), {i, j}});
        }
    }
    ini(n);
    sort(w.begin(), w.end());
    vector<pair<int, int> > path;

    for(i=0;i<w.size();i++){
        ll cam = unir(w[i].sc.ft, w[i].sc.sc, w[i].ft);
        if(cam <= 0){
            //cout<<w[i].sc.ft<<" "<<w[i].sc.sc<<endl;
            path.pb({w[i].sc.ft + 1, w[i].sc.sc + 1});
            tot += cam;
        }
    }
    cout<<tot<<endl;
    set<int> m;
    for(i=0;i<n;i++){
        m.insert(fin(i));
    }
    cout<<m.size()<<endl;
    for(auto maux: m){
        cout<<(peso[maux]+1)<<" ";
    }
    cout<<endl;
    cout<<path.size()<<endl;
    for(auto par: path){
        cout<<par.ft<<" "<<par.sc<<endl;
    }
}
