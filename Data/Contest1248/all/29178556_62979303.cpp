#include<bits/stdc++.h>
#define db double
#define ll long long
#define ev edge[i].v
#define pb push_back
#define INF 1000000007
#define Rep(i,l,r) for(int i=(l);i<=(r);++i)
#define RepD(i,r,l) for(int i=(r);i>=(l);--i)
#define RepG(i,x) for(int i=head[x];i;i=edge[i].next)
using namespace std;

const int N=1e5+5;

ll p[N],q[N];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ll t,n,m;
	scanf("%I64d",&t);
	while(t--){
		ll c1=0,c2=0,ans=0;
		scanf("%I64d",&n);
		Rep(i,1,n){
			scanf("%I64d",&p[i]);
			if(p[i]&1) c1++;
			else c2++;
		}
		scanf("%I64d",&m);
		Rep(i,1,m){
			scanf("%I64d",&q[i]);
			if(q[i]&1) ans+=c1;
			else ans+=c2;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
