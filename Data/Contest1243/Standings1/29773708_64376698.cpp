#include <cstdio>
#include <algorithm>

const int MAXN=1000+5;
int a[MAXN];

void solve() {
	int N;
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++) {
		scanf("%d",a+i);
	}
	std::sort(a+1,a+N+1);
	int ans=1;
	for(i=N;i;i--) {
		ans=std::max(ans,std::min(N-i+1,a[i]));
	}
	printf("%d\n",ans);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}