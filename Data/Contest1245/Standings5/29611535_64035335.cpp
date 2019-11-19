#include <bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define DIM 100007
#define pll pair<long long, long long>
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define mood 1000000007
#define y1 ghjhklkhkyj
#define pi 3.14159265358979323846
#define endl "\n"
typedef  pair< ll, pair<ll, ll> > ppll;

long long  n,m,l,r,h,k,res1,a1,a2,w,a3,z,alln,a4,a5,a6,a7,a8,a9,a10,last,LL,timer,start,finish,flag,step,tests,kilk,curr,shift;
string s,s1,s2;
char t;
ll x[2007],y[2007];

ll zin[2007];
ll kt[2007];

ll par[2007];
vector<pll> a;
vector<ll> b;
struct ev{
    ll dist,v1,v2;
};
vector<ev> ss;
bool cmp(ev v1,ev v2){
    return v1.dist<v2.dist;
}
ll dist(ll v1,ll v2){
    return abs(x[v1]-x[v2])+abs(y[v1]-y[v2]);
}
ll findpar(ll v1){
    if(par[v1]==v1)return v1;
    return par[v1]=findpar(par[v1]);
}

inline bool uni(ll v1,ll v2,ll w){
    ll u1,u2;
    u1=findpar(v1);
    u2=findpar(v2);
    if(u1==u2)return 0;
    ll u3=rand()%2;
    if(u3==0){
        par[u2]=u1;
    }else{
        par[u1]=u2;
    }
    return 1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++){
        cin>>zin[i];
    }
    for(int i=1;i<=n;i++){
        cin>>kt[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i!=j)
            ss.pb({dist(i,j)*(kt[i]+kt[j]),i,j});
        }
    }
    for(int i=1;i<=n;i++){
        ss.pb({zin[i],i,n+1});
    }
    n++;
    sort(ss.begin(),ss.end(),cmp);
    for(int i=1;i<=n;i++){
        par[i]=i;
    }
    m=n;
    m--;
    for(auto p:ss){
        a1=p.dist;
        a2=p.v1;
        a3=p.v2;
        //cout<<a2<<' '<<a3<<' '<<a1<<endl;
        if(uni(a2,a3,a1)){
            if(a3==n){
                a5++;
                b.pb(a2);
            }else{
                a6++;a.pb({a2,a3});
            }
            a4+=a1;

            m--;
        }
        if(m==0){
            cout<<a4<<endl;
            cout<<a5<<endl;
            for(auto p:b){
                cout<<p<<' ';
            }cout<<endl;
            cout<<a6<<endl;
            for(auto p:a){
                cout<<p.first<<' '<<p.second<<endl;
            }
            return 0;
        }
    }
    cout<<a3<<endl;
    return 0;
}
