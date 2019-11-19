#pragma GCC optimize("O3")
#include <bits/stdc++.h>   
 
#define rep(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000007
#define N 200005
#define se second
#define fi first
#define pie 3.14159265359
#define pll pair<ll,ll> 
#define pb push_back
#define sz(x) (int)x.size()
#define endl "\n"
 
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
 
typedef long long ll;
using namespace std;

void solve(){
     int n,m;
    cin>>n>>m;
    set<int>s;
    rep(i,1,n+1)s.insert(i);
    vector<ll> ans;
    vector<set<ll> > adj(N);
    rep(i,1,m+1){
        int a,b;
        cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    while(!s.empty()){
        int i=*s.begin();
        queue<int>q;
        q.push(i);
        s.erase(i);
        int cnt=1;
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            vector<ll> toerase;
            toerase.reserve(sz(s));
            for(auto j:s){
                if(adj[cur].count(j))continue;
                q.push(j);
                toerase.emplace_back(j);
                cnt++;
            }
            for(auto j:toerase)s.erase(j);
        }
        ans.pb(cnt);
    }
    cout<<sz(ans) - 1<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tc=1;
    //cin>>tc;
    while(tc--)solve();
    return 0;
}