#include "bits/stdc++.h"
#define MAXN 100009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
int mn[MAXN],k[MAXN],ata[MAXN];
int tap(int x){
	if(ata[x]==x)
		return x;
	return ata[x]=tap(ata[x]);		
}
int dis(PII x,PII y){
	return abs(x.ff-y.ff)+abs(x.ss-y.ss);	
}
PII arr[MAXN];
int canc[MAXN],kotu[MAXN],mark[MAXN];
vector<PII>kapat[MAXN];
int main(){
   // freopen("file.in", "r", stdin);
    int n;
    scanf("%d%",&n);
    for(int i=1;i<=n;i++){
    	int x,y;
		scanf("%d%d",&x,&y);
		arr[i]=mp(x,y);	
    }
    ll cur=0;
    for(int i=1;i<=n;i++)
    	scanf("%d",kotu+i),ata[i]=i,cur+=kotu[i],mn[i]=kotu[i];
    for(int i=1;i<=n;i++)
		scanf("%d",k+i);	
    vector<pair<ll,PII> >edge;
    for(int i=1;i<n;i++)
    	for(int j=i+1;j<=n;j++)
    		edge.pb(mp(dis(arr[i],arr[j])*1LL*(k[i]+k[j]),mp(i,j)));
    sort(all(edge));
    int who=0;ll can=cur;
    for(int i=0;i<edge.size();i++){
		int u=tap(edge[i].ss.ff),v=tap(edge[i].ss.ss);
		if(u!=v and min(mn[u],mn[v])+edge[i].ff<mn[u]+mn[v]){
			ata[v]=u;
			cur+=edge[i].ff;
			cur-=mn[u]+mn[v];
			umin(mn[u],mn[v]);	
			cur+=mn[u];
			canc[i]=1;
		}
		if(umin(can,cur))
			who=i+1;
	}
	printf("%lld\n",can);
	for(int i=1;i<=n;i++)
		ata[i]=i;
	vector<PII>res;	
	for(int i=0;i<who;i++){
		int u=tap(edge[i].ss.ff),v=tap(edge[i].ss.ss);
		if(u!=v and canc[i]){
			res.pb(edge[i].ss);
			ata[v]=u;
		}
	}
	for(int i=1;i<=n;i++)
		kapat[tap(i)].pb(mp(kotu[i],i));
	for(int i=1;i<=n;i++)
		if(ata[i]==i){
			sort(all(kapat[i]));
			mark[kapat[i][0].ss]=1;	
		}
	printf("%d\n",accumulate(mark+1,mark+n+1,0));
	for(int i=1;i<=n;i++)
		if(mark[i])
			printf("%d ",i);
	puts("");	
	printf("%d\n",res.size());
	tr(it,res)
		printf("%d %d\n",it->ff,it->ss);
	return 0;
}
