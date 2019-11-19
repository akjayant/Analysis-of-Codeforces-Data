#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
inline void minimize(int &x,int y) { x = min(x,y); }
inline void maximize(int &x,int y) { x = max(x,y); }

const int maxN=1000+1067,base=1e9+7;

struct Node{
    int x, y, c, k, id;
} node[maxN];

struct Edge{
    int u, v, id;
    long long w;
    Edge() {
        u=v=w=0;
    }
} edge[maxN*maxN];

int n,top;
int par[maxN],con[maxN];
bool discarded[maxN*maxN],turnedOn[maxN];
long long res;
vector<Edge> to[maxN];
vector<int> turnOn;
vector<Edge> choosenEdges;
Edge maxEdge;

int findset(int x) {
    if (par[x]==0) return x; else return findset(par[x]);
}

void uni(Edge edge) {
    int x=edge.u;
    int y=edge.v;
    x=findset(x);
    y=findset(y);
    if (x==y) return;
    res+=edge.w;
    if (con[x]<con[y]) swap(x,y);
    con[x]+=con[y];
    par[y]=x;
    to[edge.u].push_back(edge);
    to[edge.v].push_back(edge);
    choosenEdges.push_back(edge);
}

int getVer(Edge edge, int x) {
    if (edge.v==x) return edge.u; else return edge.v;
}

bool dfs(int x,int t) {
    if (turnedOn[x]) return true;
    bool rr=false;
    for(auto edge:to[x]) {
        int y=getVer(edge,x);
        if (y==t) continue;
        if (discarded[edge.id]) continue;
        bool st=dfs(y,x);
        if (st)
        if (maxEdge.w<=edge.w) {
            maxEdge=edge;
        };
        rr|=st;
    }
    return rr;
}

bool comp(Edge c1, Edge c2) {
    return c1.w<c2.w;
}

bool comp1(Node c1, Node c2) {
    return c1.c<c2.c;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("dream_hyojooslh.txt","r",stdin);
    cin>>n;
    For(i,1,n) cin>>node[i].x>>node[i].y;
    For(i,1,n) cin>>node[i].c;
    For(i,1,n) cin>>node[i].k;
    For(i,1,n) node[i].id=i;
    sort(node+1,node+n+1,comp1);

    For(i,1,n) For(j,1+i,n) {
        ++top;
        edge[top].u=i;
        edge[top].v=j;
        edge[top].id=top;
        edge[top].w=(long long)(node[i].k+node[j].k)*(abs(node[i].x-node[j].x)+abs(node[i].y-node[j].y));
    }
    sort(edge+1,edge+top+1,comp);
    For(i,1,n) con[i]=1;
    For(i,1,top) {
        uni(edge[i]);
    }

    turnedOn[1]=true;
    res+=node[1].c;
    turnOn.push_back(1);

    For(i,2,n) {
        int curNode=i;
        maxEdge.w=0;
        dfs(i,0);
        if (maxEdge.w>node[i].c) {
            res-=maxEdge.w-node[i].c;
            discarded[maxEdge.id]=true;
            turnedOn[i]=true;
            turnOn.push_back(i);
        }

    }
    cout<<res<<endl;
    cout<<(int)(turnOn.size())<<endl;
    for(auto ver:turnOn) cout<<node[ver].id<<" ";
    cout<<endl;
    cout<<n-(int)(turnOn.size())<<endl;
    for(edge:choosenEdges) if (!discarded[edge.id]) {
        cout<<node[edge.u].id<<" "<<node[edge.v].id<<endl;
    }
    return 0;
}
