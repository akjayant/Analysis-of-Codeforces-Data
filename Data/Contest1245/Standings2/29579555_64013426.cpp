#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

const int maxn=2222;
typedef long long ll;

int fa[maxn];
int findfa(int x){
    return x==fa[x]?x:(fa[x]=findfa(fa[x]));
}
int n;
ll c[maxn];
ll f[maxn];
pii point[maxn];
struct edge{
    int u,v;
    ll w;
    edge(){}
    edge(int _u,int _v,ll _w):u(_u),v(_v),w(_w){}
    bool operator<(const edge& rhs)const{
        return w<rhs.w;
    }
};
int main()
{
	while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>point[i].first>>point[i].second;
        }
        for(int i=1;i<=n;i++)cin>>c[i];
        for(int i=1;i<=n;i++)cin>>f[i];
        vector<edge> ve;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ll dis=(f[i]+f[j])*(abs(point[i].first-point[j].first)+abs(point[i].second-point[j].second));
                ve.pb(edge(i,j,dis));
            }
            ve.pb(edge(0,i,c[i]));
        }
        sort(all(ve));
        for(int i=0;i<=n;i++)fa[i]=i;
        vector<int> ans1;
        vector<pii> ans2;
        ll ans=0;
        for(int i=0;i<ve.size();i++){
            auto e=ve[i];
            int u=e.u,v=e.v;
            ll w=e.w;
            int uu=findfa(u);
            int vv=findfa(v);
            if(uu!=vv){
                fa[uu]=vv;
                ans+=w;
                if(u==0){
                    ans1.pb(v);
                }else {
                    ans2.pb(mp(u,v));
                }
            }
        }
        cout<<ans<<endl;
        cout<<ans1.size()<<endl;
        for(size_t i=0;i<ans1.size();i++){
            cout<<ans1[i];
            if(i==ans1.size()-1)cout<<endl;
            else cout<<" ";
        }
        cout<<ans2.size()<<endl;
        for(size_t i=0;i<ans2.size();i++){
            cout<<ans2[i].first<<" "<<ans2[i].second<<endl;
        }
	}
    return 0;
}
