#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
using ll=long long;

ll n,root,ans=1e18,midx;
ll c[MAX+5][3];
vector<ll> adj[MAX+5];
ll per[3]={0,1,2};
ll q[MAX+5];
ll s,e;
bool visit[MAX+5];
ll clr[MAX+5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(ll i=0; i<3; ++i){
        for(ll j=1; j<=n; ++j){
            cin>>c[j][i];
        }
    }
    for(ll u,v,i=1; i<n; ++i){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll i=1; i<=n; ++i){
        if(adj[i].size()>2){
            cout<<-1;
            return 0;
        }
    }
    for(ll i=1; i<=n; ++i){
        if(adj[i].size()==1){
            root=i;
            break;
        }
    }
    visit[root]=true;
    q[e++]=root;
    while(s<e){
        ll top=q[s++];
        for(ll x:adj[top]){
            if(!visit[x]){
                visit[x]=true;
                q[e++]=x;
            }
        }
    }
    for(ll i=0; i<6; ++i,next_permutation(per,per+3)){
        ll cnt=0;
        for(ll i=0; i<n; ++i){
            cnt+=c[q[i]][per[i%3]];
        }
        if(cnt<ans){
            midx=i;
            ans=cnt;
        }
    }
    while(midx--) next_permutation(per,per+3);
    cout<<ans<<'\n';
    for(ll i=0; i<n; ++i){
        clr[q[i]]=per[i%3]+1;
    }
    for(ll i=1; i<=n; ++i){
        cout<<clr[i]<<' ';
    }
    return 0;
}
