#include <bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define mn 100100
#define mod 1000000007
 
using namespace std;
 
typedef long long ll;
ll x[mn], y[mn], c[mn], k[mn];
struct con{ll a, b, cost;};
bool cmp(con r , con t){return r.cost<t.cost;}
vector<con> neki;

ll p[mn], siz[mn];

ll fnd(ll u){
    if (u==p[u])return u;
    return fnd(p[u]);
}
ll join(ll r, ll t){
    ll pr=fnd(r),pt=fnd(t);
    if(pr==pt) return 0;
    if(siz[pr]<siz[pt]){
        p[pr]=pt;
        siz[pt]+=siz[pr];
    }
    else{
        p[pt]=pr;
        siz[pr]+=siz[pt];
    }
    
    return 1;
}

int main() {
    ll n; cin >> n;
    loop(i, 0, n+1) p[i]=i, siz[i]=1;
    loop(i, 1, n+1) scanf("%lld%lld", &x[i], &y[i]);
    loop(i, 1, n+1) scanf("%lld", &c[i]);
    loop(i, 1, n+1) scanf("%lld", &k[i]);
    loop(i, 1, n+1){
        con temp;temp.a=0; temp.b=i;
        temp.cost=c[i];
        neki.push_back(temp);
    }
    loop(i, 1, n+1){
        loop(j, 1, i){
            con temp;temp.a=i; temp.b=j;
            temp.cost=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
            neki.push_back(temp);
        }
    }
    sort(neki.begin(), neki.end(), cmp);
    ll ans=0;
    vector<ll> v;vector<pair<ll, ll>>e;
    for(auto && era:neki){
        if(join(era.a, era.b)){
            ans+=era.cost;
            if(era.a==0) v.push_back(era.b);
            else e.push_back({era.a, era.b});
        }
    }
    cout << ans << endl;
    cout << v.size() <<endl;
    loop(i, 0, v.size()) cout << v[i]<<" ";
    if(v.size()!=0) cout << endl;
    
    cout << e.size() <<endl;
    loop(i, 0, e.size()) cout << e[i].first<<" "<<e[i].second<<endl;
}