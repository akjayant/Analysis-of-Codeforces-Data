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

#define gcd __gcd

int main() {
	scanf("%*d");
	int a,b;
	while (scanf("%d%d",&a,&b)==2) {
		puts(gcd(a,b)==1?"Finite":"Infinite");
	}
}


