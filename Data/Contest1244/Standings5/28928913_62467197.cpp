#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, ned, ned2, k;
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		if(a%c == 0) ned = a/c;
		else ned = a/c+1;
		if(b%d == 0) ned2 = b/d;
		else ned2 = b/d+1;
		if(ned + ned2 <= k){
			printf("%d %d\n", ned, ned2);
		}
		else printf("-1\n");
	}




	return 0;
}
