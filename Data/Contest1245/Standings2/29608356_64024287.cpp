#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>
#include<stack>
#include<bitset>
#include<map>
#include<unordered_map>
#include<set>
#define rep(i,n) for(int i=0;(i)<(n);i++)
#define rep1(i,n) for(int i=1;(i)<=(n);i++)
#define mst(a,b) memset(a,b,sizeof(a))
#define scd(a) scanf("%d",&a)
#define scdd(a,b) scanf("%d%d",&a,&b)
#define scddd(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define dbg(a) cout<<"* "<< #a <<" : "<<a<<endl
#define fr first
#define se second
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ls x<<1
#define rs x<<1|1
#define lowbit(x) x&(-x)
#define ac cout<<ans<<endl
//#define DEBUG 0
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-6;
const ull hashp=1e7+19;
const ll INF=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e3+100;
int p[maxn],vis[maxn],cnt,tot;
ll mn[maxn];
struct node{
	ll val;
	int a,b;
	bool operator < (const node&z) const {return val<z.val;}
}e[maxn*maxn],ans[maxn*maxn];
int xi[maxn],yi[maxn];
ll ci[maxn],ki[maxn];
int ans2[maxn],num;
int find(int x){
	return x==p[x]?x:p[x]=find(p[x]);
}
void solve()
{
    int n;scd(n);
    ll mark=0;
    rep1(i,n)scdd(xi[i],yi[i]);
	rep1(i,n){
		scanf("%lld",&ci[i]);
		mark+=ci[i];
	}
	rep1(i,n)scanf("%lld",&ki[i]);
	rep1(i,n){
    	rep1(j,i-1){
    		e[++cnt]=node{1ll*(abs(xi[i]-xi[j])+abs(yi[i]-yi[j]))*(ki[i]+ki[j]),i,j};
		}
	}
	sort(e+1,e+cnt+1);
	rep1(i,n){
    	p[i]=i;
    	mn[i]=ci[i];
	}
	rep1(i,cnt){
		int x=e[i].a,y=e[i].b;
		int xx=find(x);
		int yy=find(y);
		if(xx!=yy&&max(mn[xx],mn[yy])>e[i].val){
			p[xx]=yy;
			mark+=e[i].val-max(mn[xx],mn[yy]);
			mn[yy]=min(mn[yy],mn[xx]);
			ans[++tot]=node{0,x,y};
		}
	}
	rep1(i,n){
		int xx=find(i);
		if(!vis[xx]&&mn[xx]==ci[i]){
			vis[xx]=1;
			ans2[++num]=i;
		}
	}
	printf("%lld\n%d\n",mark,num);
	rep1(i,num)printf("%d ",ans2[i]);
	printf("\n");
	printf("%d\n",tot);
	rep1(i,tot)printf("%d %d\n",ans[i].b,ans[i].a);
}
int main(){
    //IOS;
    solve();
    return 0;
}
