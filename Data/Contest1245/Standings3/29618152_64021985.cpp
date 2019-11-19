#include <iostream>
#include <string>
#include <queue>
using namespace std;
using ll=long long;
const int MAXN=2010;
const int MAXV=2010;

struct Edge{
    int u,v;
    ll w;
    Edge(int u,int v,ll w):u(u),v(v),w(w){}
    Edge(){}
    bool operator<(const Edge &other)const{
        return w>other.w;
    }
};

struct UT{
    int fa[MAXN];
    UT(){
        for(int i=0;i<MAXN;i++)fa[i]=i;
    }

    int find(int u){
        return fa[u]==u?u:fa[u]=find(fa[u]);
    }

    bool isc(int u,int v){
        return find(u)==find(v);
    }

    void con(int u,int v){
        if(isc(u,v))return;
        fa[find(u)]=find(v);
    }
} ut;

priority_queue<Edge> pq;

struct Pos{
    ll x,y;
}pos[MAXN];
int cost[MAXN],rc[MAXN];

int superpoint=0;

vector<int> built;
vector<Edge> bedge;
int main(){
    ios::sync_with_stdio(false);
    int vlen;cin>>vlen;
    for(int i=1;i<=vlen;i++){
        cin>>pos[i].x>>pos[i].y;
    }
    for(int i=1;i<=vlen;i++)cin>>cost[i];
    for(int i=1;i<=vlen;i++)cin>>rc[i];
    for(int i=1;i<=vlen;i++){
        for(int j=1;j<=vlen;j++){
            if(i==j)continue;
            pq.push(Edge(i,j,(ll)(rc[i]+rc[j])*(abs(pos[i].x-pos[j].x)+abs(pos[i].y-pos[j].y))));
        }
    }
    superpoint=vlen+1;

    for(int i=1;i<=vlen;i++){
        pq.push(Edge(i,superpoint,cost[i]));
    }
    
    ll ans=0;
    while(!pq.empty()){
        Edge e=pq.top();pq.pop();
        if(ut.isc(e.u,e.v))continue;
        ut.con(e.u,e.v);
        if(e.u==superpoint){
            built.push_back(e.v);
        }if(e.v==superpoint){
            built.push_back(e.u);
        }else{
            bedge.push_back(e);
        }
        ans+=e.w;
    }
    cout<<ans<<endl;
    cout<<built.size()<<endl;
    for(auto i:built){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<bedge.size()<<endl;
    for(auto i:bedge){
        cout<<i.u<<" "<<i.v<<"\n";
    }

    return 0;
}