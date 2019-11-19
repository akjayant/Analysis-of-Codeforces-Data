#pragma GCC optimize("-O3")
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve();
signed main(){
#ifdef Sprinkle
   clock_t clock_start=clock();assert(freopen("test.txt","r",stdin));
#else
   ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#endif
   solve();
#ifdef Sprinkle
   cerr<<"Running Time: "<<((clock()-clock_start) *1.0 / CLOCKS_PER_SEC)<<"s\n";
#endif
}
#ifdef Sprinkle
void err(){cerr<<"\n";}template<typename T,typename...U>void err(const T&hd,const U&...tl){cerr<<hd<<(sizeof...(tl)?", ":"");err(tl...);}
#define debug(x...) cerr<<""#x" = ";err(x)
#else
#define debug(...) 0
#endif
const int N=2e5+5;
bool vis[N];
vector<int>a[N],ans;
void solve(){
    int n,m,x,y;
    list<int>g;
    list<int>::iterator it,tmp;
    cin>>n>>m;
    for(int i = 1; i<=n; ++i) g.push_back(i);
    for(int i = 1; i<=m; ++i){
        cin>>x>>y;
        a[y].push_back(x);
        a[x].push_back(y);
    }
    while(!g.empty()){
        ans.push_back(1);
        queue <int> q;
        it = g.begin();
        q.push((*it));
        g.erase(it);
        while(!q.empty()){
            memset(vis, 0, sizeof(vis));
            int u = q.front();
            q.pop();
            for(int i = 0; i < (int)a[u].size(); ++i)
                vis[a[u][i]] = 1;
            for(it = g.begin(); it != g.end();)
                if(!vis[(*it)]){
                    ++ans.back();
                    q.push((*it));
                    tmp = it;
                    ++it;
                    g.erase(tmp);
                }
                else ++it;
        }
    }
    cout<<ans.size()-1<<endl;
}