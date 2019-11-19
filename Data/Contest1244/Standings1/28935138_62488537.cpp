#include<bits/stdc++.h>
#define LL long long int
#define FIO ios::sync_with_stdio(false)
#define FRD freopen("input.txt","r",stdin)
#define lowbit(x) (x&-(x))
#define INF 1e18
#define ms(x) memset(x,0,sizeof x)
#define pb(x) push_back(x)
#define lson l,mid,now<<1
#define rson mid+1,r,now<<1|1
#define UNIQUE(x) unique(x.begin(),x.end())
#define SORT(x) sort(x.begin(),x.end())
#define LISAN(x) x.erase(UNIQUE(x),x.end())
#define pii pair<int,int>
#define pll pair<LL,LL>
#define N 100010
const LL MOD=1e9+7;
using namespace std;
template<class T> inline T Min(const T& a,const T& b){return a<b?a:b;}
template<class T> inline T Max(const T& a,const T& b){return a<b?b:a;}
inline void inc(int &x,int &v,int &mod){x+=v;if(x>=mod) x-=mod;}
inline void dec(int &x,int &v,int &mod){x-=v;if(x<0) x+=mod;}
inline int read(){char ch = getchar();int x = 0, f = 1;while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}return x * f;}
inline LL readl(){char ch = getchar();LL x = 0, f = 1;while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}return x * f;}
LL a[N];
int main(){
	#ifndef ONLINE_JUDGE
    	int startTime = clock();
		FRD;
	#endif
	FIO;
	LL n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n,lcnt=1,rcnt=1;
	LL ans=a[r]-a[l];
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<' ';
//	cout<<endl;
	while(l<r&&k>0){
		//cout<<l<<' '<<r<<' '<<k<<endl;
		if(lcnt<=rcnt){
			LL del=a[l+1]-a[l];
			if(del*lcnt<=k){
				k-=del*lcnt;
				l++;lcnt++; 
				ans=a[r]-a[l];
			}
			else{
				ans-=k/lcnt;
				break;
			}
		}
		else{
			LL del=a[r]-a[r-1];
			if(del*rcnt<=k){
				k-=del*rcnt;
				r--;rcnt++; 
				ans=a[r]-a[l];
			}
			else{
				ans-=k/rcnt;
				break;
			}
		}
	}
	cout<<ans<<endl;
	#ifndef ONLINE_JUDGE
    	printf("Time = %dms\n", clock() - startTime);
	#endif
	return 0;
}









