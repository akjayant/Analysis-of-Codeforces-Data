#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
int par[N],siz[N];
int cnt[N];
struct edge{
    int u,v,w;
}e[N];
vector<int> G[N];
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return ;
    par[x]=y;
    siz[y]+=siz[x];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        par[i]=i;
        siz[i]=1;
    }
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans=n-1;
    set<int> st;
    st.insert(1);
    for(int i=2;i<=n;i++){
        for(int v:G[i]){
            cnt[find(v)]++;
        }
        for(auto it=st.begin();it!=st.end();){
            int an=find(*it);
            if(cnt[an]<siz[an]){
                unite(*it,i);
                st.erase(it++);
                ans--;
            }else it++;
        }
        for(int v:G[i]) cnt[find(v)]=0;
        st.insert(i);
    }
    cout<<ans<<endl;
    return 0;
}