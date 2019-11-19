#include<bits/stdc++.h>
#define For(a,b,c) for(int a=b;a<=c;++a)
#define Dor(a,b,c) for(int a=b;a>=c;--a)
using namespace std;
void sol() {
	int a,b,c,d,k;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
	int x=(a+c-1)/c,y=(b+d-1)/d;
	if(x+y<=k) printf("%d %d\n",x,y);
	else puts("-1");
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) sol();
	return 0;
}