#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define ll long long
#define inf 0x7f7f7f7f
using std::queue;
using std::map;
using std::multiset;
using std::vector;
const int maxn=4e5+6;
template<class T>inline void read(T &x) {
   	T f=1;x=0;char s=getchar();
   	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
   	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s&15);s=getchar();}
   	x*=f;
}
template<class T>inline T min(T a,T b) { return a<b?a:b; }
template<class T>inline T max(T a,T b) { return a>b?a:b; }
template<class T>inline T fabs(T a) { return a>0?a:-a; }
int t,a,b,c,d,k,ans1,ans2;
int main() {
	read(t);
	while(t--) {
		read(a); read(b); read(c); read(d); read(k);
		ans1=(a/c)+((a%c)!=0); ans2=(b/d)+((b%d)!=0);
		if(ans1+ans2<=k) printf("%d %d\n",ans1,ans2);
		else printf("-1\n");
	}
}