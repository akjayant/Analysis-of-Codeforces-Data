#include <bits/stdc++.h>
using namespace std;
  

#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz(a) (int)a.size()
#define mod 1000000007
#define dbg(a) cout<<#a<<" = "<<a<<endl
#define dbg2(a,b) cout<<#a<<" = "<<a<<", "<<#b<<" = "<<b<<endl
#define dbg3(a,b,c) cout<<#a<<" = "<<a<<", "<<#b<<" = "<<b<<", "<<#c<<" = "<<c<<endl
#define dbg4(a,b,c,d) cout<<#a<<" = "<<a<<", "<<#b<<" = "<<b<<", "<<#c<<" = "<<c<<", "<<#d<<" = "<<d<<endl
#define ll long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>

const int nax = 1e5+5;
int c[4][nax], take[3]={1,2,3},ctr;
ll ans=(ll)1e18,cur;
vi adj[nax];
int prt[nax], tmp[nax];

void dfs(int u,int p){
    cur+=c[take[ctr]][u];
    tmp[u] = take[ctr];
    ctr++;ctr%=3;
    for(int v:adj[u]){
        if(v!=p) dfs(v,u);
    }
}


void solve()
{
    int n;cin>>n;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int st=-1;
    for(int i=1;i<=n;i++){
        if(sz(adj[i])==1) st=i;
        else if(sz(adj[i])>2){
            cout<<-1;
            return;
        }
    }
    for(int i=1;i<=6;i++){
        dfs(st,st);
        if(cur<ans){
            ans=cur;
            for(int j=1;j<=n;j++){
                prt[j] = tmp[j];
            }
        }
        ctr=0;cur=0;
        next_permutation(take,take+3);
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) cout<<prt[i]<<" ";
}
 

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(13);
    clock_t beg=clock();
    int t = 1; 
    // cin>>t;
    // n = t;
    while(t--){
        // cout << "Case #" << n-t << ": ";
        solve();
    }
    //
    clock_t end=clock();
    fprintf(stderr, "%lf sec\n", (double)(end-beg)/(CLOCKS_PER_SEC));
    return 0;
}