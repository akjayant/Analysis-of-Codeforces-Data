//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}

const int N=200005;

int n,k,a[N],b[N],s[N],cnt[N];

signed main(){
	rd(n),rd(k);
	rep(i,1,n)rd(a[i]);
	std::sort(a+1,a+1+n);
	rep(i,1,n)b[i]=a[i];
	int m=std::unique(b+1,b+1+n)-b-1;
	rep(i,1,n)++cnt[std::lower_bound(b+1,b+1+m,a[i])-b];
	int mn=1,mx=m,ans=0,tmp=0;
	while(1){
		if(mn>=mx)break; 
		if(cnt[mn]<cnt[mx]){
			if((b[mn+1]-b[mn])*cnt[mn]<=k){
				k-=(b[mn+1]-b[mn])*cnt[mn];
			}else{
				tmp=k/cnt[mn];
				break;
			}
			cnt[mn+1]+=cnt[mn];
			++mn;
		}else{
			if((b[mx]-b[mx-1])*cnt[mx]<=k){
				k-=(b[mx]-b[mx-1])*cnt[mx];
			}else{
				tmp=k/cnt[mx];
				break;
			}
			cnt[mx-1]+=cnt[mx];
			--mx;
		}
	}
	ans=b[mx]-b[mn]-tmp;
	pt(ans,'\n');
	return 0;
}