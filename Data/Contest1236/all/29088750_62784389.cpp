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

int T,a,b,c,ans;
int main(){
	readint(T);
	while(T--){
		readint(a);
		readint(b);
		readint(c);
		ans=0;
		while(b>=1 && c>=2){
			--b;
			c-=2;
			ans+=3;
		}
		while(a>=1 && b>=2){
			--a;
			b-=2;
			ans+=3;
		}
		prtint(ans);
		puts("");
	}
	return 0;
}
