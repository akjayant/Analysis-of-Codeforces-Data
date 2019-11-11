#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#define fo(i,l,r) for (auto i=l,_end=r;i<=_end;++i)
#define fd(i,l,r) for (auto i=l,_end=r;i>=_end;--i)
#define FI(x) freopen(x,"r",stdin)
#define FO(x) freopen(x,"w",stdout)
using ll=long long;
using namespace std;

const int N=128;

int n,a[3];
char s[N];
int x[N],y[N];

int main() {
	scanf("%*d");
	while (scanf("%d%d%d%d%s",&n,a+0,a+1,a+2,s)==5) {
		fo(i,0,n-1) fo(j,0,2) if (s[i]=="RPS"[j]) x[i]=j;
		memset(y,-1,sizeof y);
		int cnt=0;
		fo(i,0,n-1) {
			auto t=(x[i]+1)%3;
			if (a[t]) {
				a[t]--;
				y[i]=t;
				cnt++;
			}
		}
		fo(i,0,n-1) if (y[i]==-1) fo(j,0,2) if (a[j]) {
			a[j]--;
			y[i]=j;
			break;
		}
		
		if (cnt>=(n+1)/2) {
			puts("YES");
			fo(i,0,n-1) putchar("RPS"[y[i]]);
			puts("");
		} else puts("NO");
	}
}


