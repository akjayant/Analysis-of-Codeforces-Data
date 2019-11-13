#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
int a[maxn],n;
int T;
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",a+i);
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		int ans = 0;
		for(int i=1;i<=n;++i) {
			if(a[i] < i ) {
				break;
			}
			ans = min(i,a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
