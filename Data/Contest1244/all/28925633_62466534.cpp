#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=1e2+5;
#define LL long long
int T,a,b,c,d,k;
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int A=(a+c-1)/c,B=(b+d-1)/d;
		if(A+B<=k)printf("%d %d\n",k-B,B);
		else printf("-1\n");
	}
}