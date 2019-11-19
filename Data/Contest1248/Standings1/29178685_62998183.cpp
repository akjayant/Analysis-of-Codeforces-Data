#include<bits/stdc++.h>
#include <iterator>
using namespace std;
#define ll long long
#define M 1000000007LL
#define M1 1000000009LL
#define sz(a) (ll)a.size()
#define rep(i,a,b) for( i=a;i<b;i++)
#define sep(i,a,b) for((ll) i=(ll)a;i>=(ll)b;i--)
#define mll map<ll,ll>
#define vl vector<ll>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pii pair<ll,ll>
#define MAXN 1000002
#define ppi pair<ll,pair<ll,ll> >
#define INF 1e7
#define mp make_pair
#define trace1(x)                cerr << #x << ": " << x << "\n";
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";
vector<int> odr,cmp;
vector<bool> vis;
void dfs1(int v,vector<vector<int> > &g1){
    vis[v]=true;
    for(int i=0;i<g1[v].size();i++){
        if(!vis[g1[v][i]])dfs1(g1[v][i],g1);
    }
    odr.pb(v);
}
void dfs2(int v,vector<vector<int> >&g2){
    vis[v]=true;
    cmp.pb(v);
    for(int i=0;i<g2[v].size();i++){
        if(!vis[g2[v][i]])dfs2(g2[v][i],g2);
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<int> > g1(n),g2(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        //cout<<"ye"<<endl;
        if(a==b)continue;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }
    odr.clear();
    cmp.clear();
    vis.assign(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i])dfs1(i,g1);
    }
    vis.assign(n,false);
    set<int> ss;
    set<int> s;
    bool b=true;
    int k=0;
    for(int i=0;i<n;i++){
        int v=odr[n-1-i];
        if(!vis[v]){
            dfs2(v,g2);
            if(b){
                for(int j=0;j<cmp.size();j++)ss.insert(cmp[j]+1);
                b=false;
            }
            else{
                    k=1;
                for(int j=0;j<cmp.size();j++)s.insert(cmp[j]+1);
            }
            //for(int j=0;j<cmp.size();j++)cout<<cmp[j]
            cmp.clear();
        }
    }
    if(k==0){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n"<<s.size()<<" "<<ss.size()<<"\n";
        set<int>::iterator it;
        for(it=s.begin();it!=s.end();it++){
            cout<<*it<<" ";
        }
        cout<<"\n";
        for(it=ss.begin();it!=ss.end();it++){
            cout<<*it<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
