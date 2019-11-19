#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		int s1=-1,s2=-1;
		if(a%c==0)s1=a/c;
		else s1=a/c+1;
		if(b%d==0)s2=b/d;
		else s2=b/d+1;
		if(s1+s2>k)puts("-1");
		else printf("%d %d\n",s1,s2);
	}
	return 0;
}