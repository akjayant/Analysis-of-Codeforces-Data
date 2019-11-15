#include <cstdio>
#include <cctype>
#define MY_READ {char c;bool nega=false;while(!isdigit(c=getchar()))if(c=='-')nega=true;x=(c^48);while(isdigit(c=getchar()))x=x*10+(c^48);if(nega)x=-x;}
#define MY_MIN {return a<b?a:b;}
#define MY_MAX {return a>b?a:b;}
using namespace std;
typedef long long ll;
inline void readint(int &x) MY_READ inline void prtint(ll x){if(x<0)putchar('-'),x=-x;if(x>=10)prtint(x/10);putchar(x%10|48);return;}
inline void readll(ll &x) MY_READ inline void prtll(ll x){if(x<0)putchar('-'),x=-x;if(x>=10)prtll(x/10);putchar(x%10|48);return;}
inline int mmin(int a,int b) MY_MIN inline ll mmin(ll a,ll b) MY_MIN inline ll mmin(ll a,int b) MY_MIN inline ll mmin(int a,ll b) MY_MIN
inline int mmax(int a,int b) MY_MAX inline ll mmax(ll a,ll b) MY_MAX inline ll mmax(ll a,int b) MY_MAX inline ll mmax(int a,ll b) MY_MAX

int n,a[301][301];
int main(){
	readint(n);
	int i,j,x=0;
	for(i=1;i<=n;++i){
		if(i&1){
			for(j=1;j<=n;++j){
				a[j][i]=++x;
			}
		}else{
			for(j=n;j>=1;--j){
				a[j][i]=++x;
			}
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			prtint(a[i][j]);
			putchar(' ');
		}
		puts("");
	}
	return 0;
}
