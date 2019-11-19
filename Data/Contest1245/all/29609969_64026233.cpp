#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> dsu;

ll par(ll x){
    while(dsu[x]!=x){
        dsu[x] = dsu[dsu[x]];
        x =dsu[x];
    }
    return x;
}

void un(ll x, ll y){
    ll px = par(x);
    ll py = par(y);
    if(px!=py){
        dsu[py] = px;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    priority_queue<pair<ll, pair<ll,ll> >, vector<pair<ll, pair<ll,ll> >>, greater<pair<ll, pair<ll,ll> >>> pque;
    vector<ll> x(n);
    vector<ll> y(n);
    
    for(ll i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }

    vector<ll> k(n);
    vector<ll> c(n);

    for(ll i=0; i<n; i++){
        cin>>c[i];
    }
    for(ll i=0; i<n; i++){
        cin>>k[i];
    }
    ll ans=0;
    dsu = vector<ll> (n+1);
    dsu[n] = n;
    for(ll i=0; i<n; i++){
        dsu[i] = i; 
        pque.push({c[i],{0, i+1}});
        for(ll j=i+1; j<n; j++){
            pque.push({(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])),{i+1, j+1}});
        }
    }
    vector<ll> p;
    vector<pair<ll, ll> > edges;
    while(!pque.empty()){
        auto it = pque.top();
        pque.pop();
        ll x1 = it.second.first;
        ll x2 = it.second.second;
        if(par(x1)!=par(x2)){
            un(x1, x2);
            ans += it.first;
            if(x1==0){
                p.push_back(x2);
            } else {
                edges.push_back({x1, x2});
            }
        }
    }

    cout<<ans<<endl;
    cout<<p.size()<<endl;
    for(auto it:p){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<edges.size()<<endl;
    for(auto it:edges){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}