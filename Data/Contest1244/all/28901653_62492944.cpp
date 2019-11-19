// I can't live in a fairytale of lies

#include<bits/stdc++.h>

#define s second
#define f first
#define pb push_back
#define int ll
#define D(x) cerr<<#x<<": "<<x<<endl
#define D2(x) cerr<<#x<<": "<<x<<' '

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int MAX=1e5+50,mod=1e9+7,INF=1e15,sq=320;

int n,k,q,m,a[5],b,d,col[MAX],c[4][MAX];
vi adj[MAX];
string s;
bool mark[MAX];

/*void compress(){
    for(int i=0;i<n;i++) v.pb(a[i]);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=0;i<n;i++){
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin()+1;
    }
}*/

void dfs(int v,int c1,int c2, int c3){
    mark[v] = 1;
    for(int i=0;i<adj[v].size();i++){
        int u = adj[v][i];
        if(!mark[u]){
            col[u] = c3;
            dfs(u,c3,c1,c2);
        }
    }
}

void solve(int x,int y, int z){
    for(int i=1;i<=n;i++){
        if(col[i]==x) cout << 1 << ' ';
        if(col[i]==y) cout << 2 << ' ';
        if(col[i]==z) cout << 3 << ' ';
    }
    exit(0);
}

main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> c[0][i];
    for(int i=1;i<=n;i++) cin >> c[1][i];
    for(int i=1;i<=n;i++) cin >> c[2][i];
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vi v1,v2;
    for(int i=1;i<=n;i++) if(adj[i].size()==1) v1.pb(i);
    for(int i=1;i<=n;i++) if(adj[i].size()==2) v2.pb(i);
    if(v1.size()!=2 || v2.size()!=n-2) return cout << -1, -0;
    col[v1[0]]=0;
    dfs(v1[0],0,1,2);
    int ans = 0,cnt = INF;
    for(int i=1;i<=n;i++){
        if(col[i] == 0) ans+= c[0][i];
        if(col[i] == 1) ans+= c[1][i];
        if(col[i] == 2) ans+= c[2][i];
    }
    if(ans<cnt){
        cnt = ans;
        a[0] = 0;
        a[1] = 1;
        a[2] = 2;
    }
    ans = 0;
    for(int i=1;i<=n;i++){
        if(col[i] == 0) ans+= c[0][i];
        if(col[i] == 2) ans+= c[1][i];
        if(col[i] == 1) ans+= c[2][i];
    }
    if(ans<cnt){
        cnt = ans;
        a[0] = 0;
        a[1] = 2;
        a[2] = 1;
    }
    ans = 0;
    for(int i=1;i<=n;i++){
        if(col[i] == 1) ans+= c[0][i];
        if(col[i] == 0) ans+= c[1][i];
        if(col[i] == 2) ans+= c[2][i];
    }
    if(ans<cnt){
        cnt = ans;
        a[0] = 1;
        a[1] = 0;
        a[2] = 2;
    }
    ans = 0;
    for(int i=1;i<=n;i++){
        if(col[i] == 1) ans+= c[0][i];
        if(col[i] == 2) ans+= c[1][i];
        if(col[i] == 0) ans+= c[2][i];
    }
    if(ans<cnt){
        cnt = ans;
        a[0] = 1;
        a[1] = 2;
        a[2] = 0;
    }
    ans = 0;
    for(int i=1;i<=n;i++){
        if(col[i] == 2) ans+= c[0][i];
        if(col[i] == 1) ans+= c[1][i];
        if(col[i] == 0) ans+= c[2][i];
    }
    if(ans<cnt){
        cnt = ans;
        a[0] = 2;
        a[1] = 1;
        a[2] = 0;
    }
    ans = 0;
    for(int i=1;i<=n;i++){
        if(col[i] == 2) ans+= c[0][i];
        if(col[i] == 0) ans+= c[1][i];
        if(col[i] == 1) ans+= c[2][i];
    }
    if(ans<cnt){
        cnt = ans;
        a[0] = 2;
        a[1] = 0;
        a[2] = 1;
    }
    cout << cnt << '\n';
    solve(a[0],a[1],a[2]);
}



