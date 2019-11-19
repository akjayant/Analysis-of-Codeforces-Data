#include<cstdio>
#include<algorithm>
using namespace std;
int t,a,b,c,d,k;
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		int x=(a+c-1)/c,y=(b+d-1)/d;
		if(x+y>k) printf("-1\n");
		else printf("%d %d\n",x,y);
	}
	return 0;
}