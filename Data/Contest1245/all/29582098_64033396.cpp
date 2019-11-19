#pragma GCC optimize ("2")
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef pair<int,int> pr;
const int mxn = 2510;
const int mxm = 7e6+5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-7;
const double pii = 3.1415926535898;
#define mpr make_pair
int gcd(int x,int y){if(y==0) return x; else return gcd(y,x%y);}
int qpow(int a,int b){int ans=1; while(b){ if(b&1) ans=ans*a%mod; b>>=1; a=a*a%mod; } return ans;}
int lowbit(int x){return (x&(-x));}
int qmul(int a,int b){int ans=0; while(b){ if(b&1) ans=(ans+a)%mod; b>>=1; a=(a+a)%mod; } return ans; }
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int inf = 999999999999999999LL;
int cost[mxn][mxn],x[mxn],y[mxn],c[mxn],k[mxn];
int fa[mxn],dis[mxn];
int n;
int prim(){
	int sum=0;
	int cnt=0;
	int s=n+1;
	for(int i=1;i<=n;i++) dis[i]=cost[s][i],fa[i]=s;
	cnt++;
	while(1){
		int mn=inf;
		int now=-1;
		for(int i=1;i<=n;i++){
			if(dis[i]!=0&&dis[i]<mn){
				mn=dis[i];
				now=i;
			}
		}
		if(now==-1) break;
		sum+=dis[now];
		dis[now]=0;
		cnt++;
		for(int i=1;i<=n;i++){
			if(dis[i]!=0&&cost[now][i]<dis[i]){
				dis[i]=cost[now][i];
				fa[i]=now;
			}
		}
	}
	if(cnt<n) return -1;
	else return sum;
}
signed main(void){
//    int n;
    scanf("%lld",&n);
//    for(int i=1;i<=n+5;i++) fa[i]=i;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&y[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int dis = llabs(x[i]-x[j]) + llabs(y[i] - y[j]);
            cost[i][j] = dis * (k[i]+k[j]);
//            printf("i=%lld,j=%lld,cost=%lld\n",i,j,cost[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        cost[n+1][i] = c[i];
    }
//    m = n*(n-1)/2 + n;
//    for(int i=1;i<=n;i++){
//        for(int j=i+1;j<=n;j++){
//            addedge(i,j,cost[i][j]);
//        }
//    }
//    for(int i=1;i<=n;i++){
//        addedge(n+1,i,c[i]);
//    }
//    kruskal(n+1);
    int res = prim();
    printf("%lld\n",res);
    vector<int> pp;
    vector<pr>qq;
    for(int i=1;i<=n;i++){
        if(fa[i]==n+1){
            pp.pb(i);
        }
        else{
            qq.pb(mpr(fa[i],i));
        }
    }
    printf("%lld\n",(long long int)pp.size());
    for(int i=0;i<pp.size();i++){
        printf("%lld ",pp[i]);
    }
    printf("\n");
    printf("%lld\n",(long long int)qq.size());
    for(int i=0;i<qq.size();i++){
        printf("%lld %lld\n",qq[i].fi,qq[i].se);
    }
}
