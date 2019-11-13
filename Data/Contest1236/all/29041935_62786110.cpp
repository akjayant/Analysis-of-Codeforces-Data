#include <cstdio>
#include <iostream>
using namespace std;

int T,a,b,c;

int main() {
	scanf("%d",&T);
	while(T--) {
		int ans=0;
		scanf("%d%d%d",&a,&b,&c);
		for (int x=0;x<=100;x++) {
			for (int y=0;y<=100;y++) {
				if (x<=a && 2*x+y<=b && 2*y<=c) {
					ans=max(ans,3*(x+y));
				}
			}
		}
		printf("%d\n",ans);
	}
}