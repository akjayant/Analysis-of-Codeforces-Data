#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inarr(a,k,n) for(int i=k;i<n;i++){cin>>a[i];}
#define outarr(a,k,n) for(int i=k;i<n;i++){cout<<a[i]<<" ";}
#define inpair(a) cin>>a.first>>a.second
#define outpair(a) cout<<a.ff<<" "<<a.ss<<endl
#define in2(a,b) cin>>a>>b
#define in3(a,b,c) cin>>a>>b>>c
#define fastio ios_base::sync_with_stdio(false)
ll gcd(ll a,ll b){
    if(a==0)return b;
    b%=a;
    return gcd(b,a);
}
vector<int> adj[100005];
ll clr[100005][3]={0};
ll ansc[100005]={0};
int sm;bool prt=false;
ll dfs(int k,int p,int c){
    c+=sm;c%=3;
    if(prt)ansc[k]=c;
    ll ret = clr[k][c];
    for(int h : adj[k]){
        if(h==p)continue;
        ret+=dfs(h,k,c);
    }
    return ret;
}
int main(){
    fastio;
    int t=1;
    //cin>>t;
    while(t--){
        int n;cin>>n;
        int i=1;
        while(i<=n){cin>>clr[i][0];i++;}
        i=1;
        while(i<=n){cin>>clr[i][1];i++;}
        i=1;
        while(i<=n){cin>>clr[i][2];i++;}
        i=0;int x,y;
        bool a = true;
        while(i<n-1){
            in2(x,y);
            adj[x].pb(y);adj[y].pb(x);
            if((adj[x].size()>2) || (adj[y].size()>2))a=false;
            i++;
        }
        if(!a){cout<<-1<<endl;continue;}
        i=1;x=-1;
        while(x<=n){
            if(adj[i].size()<=1){x=i;break;}i++;
        }
        if(x==-1){cout<<-1<<endl;continue;}
        sm=1;
        ll ans = dfs(x,0,0);
        int rsm=1;int s=0;
        //
        ll tmp=dfs(x,0,1);
        if(ans>tmp){ans=tmp;s=1;}
        tmp=dfs(x,0,2);
        if(ans>tmp){ans=tmp;s=2;}
        //
        sm=2;
        tmp=dfs(x,0,0);
        if(ans>tmp){ans=tmp;s=0;rsm=2;}
        tmp=dfs(x,0,1);
        if(ans>tmp){ans=tmp;s=1;rsm=2;}
        tmp=dfs(x,0,2);
        if(ans>tmp){ans=tmp;s=2;rsm=2;}
        prt=true;sm=rsm;
        ans = dfs(x,0,s);
        cout<<ans<<endl;
        i=1;
        while(i<=n){
            cout<<ansc[i]+1<<" ";i++;
        }
        cout<<endl;
    }
    return 0;
}
