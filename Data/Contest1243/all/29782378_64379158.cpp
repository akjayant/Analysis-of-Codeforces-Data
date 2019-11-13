#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=10000;
int a[maxn];

int main() {
	int T;
	scanf("%d", &T);
	
	while (T--) {
//		printf("!!!\n");
		int n;
		scanf("%d", &n);
		for (int i=1;i<=n;i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1,a+n+1);
		int ans=0;
		for (int i=n;i>=1;i--) {
			if (ans<min(n-i+1,a[i])) {
				ans=min(n-i+1,a[i]);
			}
		}
		printf("%d\n", ans);
		
//		printf("???\n");
	}
	return 0;
}
/*
4
5
4 3 1 4 5
4
4 4 4 4
3
1 1 1
5
5 5 1 1 5

*/
