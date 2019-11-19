#include<bits/stdc++.h>
using namespace std;
#define For(a,b,c) for(int a=b;a<=c;++a)
#define Ford(a,b,c) for(int a=b;a>=c;--a)
#define Fv(a,b) for(auto &a:b)
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define vt vector<int>
#define vpi vector<pair<int,int>>
#define sz(x) (int)(x.size())
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) (x>>i&1ll)
#define on(x,i) (x|(1ll<<i))
#define off(x,i) (x&~(1ll<<i))
#define task "1243c"
#define int long long
const int N=1e5+5;
int n,id[N],vis[N],cc[N],m,d,cnt;
vector<int>ad[N],gr[N];
vpi E;
int root(int x){return id[x]==x?x:id[x]=root(id[x]);}
void bfs(int s){
    queue<int>q;
    q.push(s);
    id[s]=root(s+1);
    gr[cnt].pb(s);
    cc[s]=cnt;
    while(!q.empty()){
        int x=q.front();q.pop();
        Fv(v,ad[x]){
            vis[v]=x;
        }
        for(int i=root(1); i <= n; i = root(i + 1)) {
            if(vis[i]!=x) id[i]=root(i+1),q.push(i),gr[cnt].pb(i),cc[i]=cnt;
        }
    }
    ++cnt;
}
string ss[N];
void upd(int i, char c, int id){Fv(v,gr[i])ss[id][v-1]=c;}
void get2(int x,int id){d=max(id,d);if(x==1||x==2)return;get2(x/2,id+1);get2(x-x/2,id+1);}
inline void get(int j, int x, int id) {
  if(x == 1) {
        return;
  }
  else if(x == 2) {
    //upd(j, '0', id);
    upd(j + 1, '1', id);
    //for(int i = id + 1 ; i < d ; ++i) upd(j, '0', i), upd(j + 1, '0', i);
  }
  else {
    int xx = x / 2;
    //for(int i = 0 ; i < xx ; ++i) upd(j + i, '0', id);
    for(int i = xx ; i < x ; ++i) upd(j + i, '1', id);
    get(j, xx, id + 1);
    get(j + xx, x - xx, id + 1);
  }
}

main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    For(i,1,m){
        int u,v;
        cin>>u>>v;
        ad[u].pb(v);ad[v].pb(u);
    }
    For(i,1,n+1)id[i]=i;
    for(int i=1;i<=n;i=root(i+1)) bfs(i);
    get2(cnt,0);
    d++;
    For(i,0,n-1) ss[0].pb('0');
    For(i,1,d-1) ss[i]=ss[0];
    get(0,cnt,0);
    cout<<cnt-1;
}
