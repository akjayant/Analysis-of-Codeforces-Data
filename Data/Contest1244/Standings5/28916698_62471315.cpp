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
int t,n,ans1,ans2,rans;
char s[1001];
int main() {
	read(t);
	while(t--) {
		read(n);
		ans1=0; ans2=0; rans=n;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++) {
			if(s[i]=='1') { ans1=(n-i+1); break; }
		}
		for(int i=n;i>=1;i--) {
			if(s[i]=='1') { ans2=i; break; }
		}
		if(ans1||ans2) rans=max(rans,max((ans1<<1),(ans2<<1)));
		printf("%d\n",rans);
	}
}