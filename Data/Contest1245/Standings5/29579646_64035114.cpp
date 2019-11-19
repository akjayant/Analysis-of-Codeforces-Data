#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int maxn=2005;
const int maxm=4e6+50;

struct Edge{
    int u,v;
    ll w;
    Edge(int uu=0,int vv=0,ll ww=0):u(uu),v(vv),w(ww){}
    bool operator<(const Edge& e)const{
        return w<e.w;
    }
};

int n,x[maxn],y[maxn],c[maxn],k[maxn],par[maxn];
vector<Edge> edges;
vector<int> res1;
vector<P> res2;

int find(int a){
    if(a==par[a]) return a;
    return par[a]=find(par[a]);
}

int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&x[i],&y[i]);
    }
    for(int i=1;i<=n;++i) scanf("%d",&c[i]);
    for(int i=1;i<=n;++i) scanf("%d",&k[i]);
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            ll w=abs(x[i]-x[j])+abs(y[i]-y[j]);
            w*=k[i]+k[j];
            edges.push_back(Edge(i,j,w));
        }
        edges.push_back(Edge(0,i,1LL*c[i]));
    }

    for(int i=0;i<=n;++i) par[i]=i;
    for(int i=1;i<=n;i++){
    	for(int j=i+1;j<=n;j++){
    		if(x[i]==x[j]&&y[i]==y[j]){
    			par[j]=par[i];
			}
		}
	}
    sort(edges.begin(),edges.end());
    ll ans=0;
    for(int i=0;i<(int)edges.size();++i){
        int u=edges[i].u,v=edges[i].v;
        ll w=edges[i].w;
        int x=find(u);
        int y=find(v);
        if(x!=y){
            if(!u) res1.push_back(v);
            else if(!v) res1.push_back(u);
            else
                res2.push_back(make_pair(u,v));
            ans+=w;
            par[x]=y;
        }
    }

    printf("%I64d\n",ans);
    printf("%d\n",(int)res1.size());
    for(int i=0;i<(int)res1.size();++i) printf("%d%c",res1[i],i+1==(int)res1.size()?'\n':' ');
    printf("%d\n",(int)res2.size());
    for(int i=0;i<(int)res2.size();++i) printf("%d %d\n",res2[i].first,res2[i].second);
    return 0;
}

