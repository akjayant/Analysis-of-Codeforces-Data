#include<bits/stdc++.h>
#define Rint register int
using namespace std;
int t, a, b, c, d, k;
int main(){
	scanf("%d", &t);
	while(t --){
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int t1 = (a + c - 1) / c, t2 = (b + d - 1) / d;
		if(t1 + t2 <= k) printf("%d %d\n", t1, t2);
		else printf("-1\n");
	}
}