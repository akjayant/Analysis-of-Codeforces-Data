#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
using namespace std;
#define int     long long int
#define ld      long double
#define pb      push_back
#define pa      pair<int,int>
#define ppa     pair<pair<int,int>,int>
#define pap     pair<int,pair<int,int>>
#define v1d     vector<int>
#define v2d     vector<vector<int> >
#define vpa     vector<pair<int,int>>
#define M       1000000007
#define MN      LLONG_MIN
#define MX      LLONG_MAX
#define ff      first
#define ss      second
#define endl    "\n"
#define v1s     vector<string>
#define all(v)  v.begin(),v.end()
#define S(v)    sort(v.begin(),v.end())
#define RS(v)   sort(v.rbegin(),v.rend())
#define R(v)    reverse(v.begin(),v.end())
#define mxpq(T)    priority_queue <T>
#define mnpq(T)    priority_queue<T,vector<T>,greater<T>>
#define T       int tc;cin>>tc;while(tc--)
#define p2d(v)     for(auto a:v){for(auto b:a)cout<<b<<" ";cout<<endl;}
#define p1d(v)      for(auto a:v)cout<<a<<" ";cout<<endl;
#define ppd(v)      for(auto a:v)cout<<a.ff<<" "<<a.ss<<endl;

#define qqq 2005
v1d cost(qqq);
v2d g(qqq);
class DS{
     public:
    vector<int>parent;
    vector<int>nodes;
    DS(int n){
        parent.resize(n+1);
        nodes.resize(n+1);
        for(int i=0;i<=n;i++){parent[i]=i;nodes[i]=1;}
    }
    void join(int a,int b){
        int x=findparent(a),y=findparent(b);
        if(x==y)return;
        parent[x]=y;
        nodes[y]+=nodes[x];
    }
    int findparent(int a){
        if(a==parent[a])return a;
        parent[a]=findparent(parent[a]);
        return parent[a];
    }
 };
 map<pa,int>edge;
void pontifex_maximus(){
    int n;cin>>n;
    vpa ct(n+1);
    for(int i=1;i<=n;i++){
        cin>>ct[i].ff>>ct[i].ss;
    }
    vector<pair<int,pa>>z;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
        //g[0].pb(i);
        //g[i].pb(0);
        z.pb({cost[i],{0,i}});
        //edge[{}]
    }
    v1d k(n+1);
    for(int i=1;i<=n;i++)cin>>k[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int a=abs(ct[i].ff-ct[j].ff)+abs(ct[i].ss-ct[j].ss);
            a=a*(k[i]+k[j]);
            z.pb({a,{i,j}});
        }
    }
    S(z);
    DS ww(n);
 int ans=0;
 vpa w;
    for(auto a:z){
        if(ww.findparent(a.ss.ff)!=ww.findparent(a.ss.ss)){
            ww.join(a.ss.ff,a.ss.ss);
            g[a.ss.ff].pb(a.ss.ss);
            g[a.ss.ss].pb(a.ss.ff);
            w.pb({a.ss.ss,a.ss.ff});
            edge[{a.ss.ff,a.ss.ss}]=a.ff;
            edge[{a.ss.ss,a.ss.ff}]=a.ff;
            ans+=a.ff;
        }
    }
    cout<<ans<<endl;
    cout<<g[0].size()<<endl;
    map<int,int>vis;vis[0]=1;
    for(auto a:g[0]){cout<<a<<" ";vis[a]++;}
        int count=0;
    vpa e;
    cout<<endl;
    for(auto a:w){
        if(vis[a.ff]==0||vis[a.ss]==0){
            count++;
            e.pb(a);
        }
    }
    cout<<count<<endl;
    ppd(e);























}


int32_t main(){

    cout<<fixed<<setprecision(16);
    cin.sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
     freopen("input.txt",  "r",  stdin);
     freopen("output.txt", "w", stdout);
    #endif

    pontifex_maximus();
    
}



