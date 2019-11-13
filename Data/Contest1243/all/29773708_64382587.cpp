#include <cstdio>

const int MAXN=10000+5;
char S[MAXN],T[MAXN];

void solve() {
	int N;
	scanf("%d",&N);
	scanf("%s%s",S+1,T+1);
	int cnt=0,i,j;
	for(i=1;i<=N;i++) {
		cnt+=(S[i]!=T[i]);
	}
	if(cnt!=2) {
		printf("No\n");
		return;
	}
	for(i=1;i<=N&&S[i]==T[i];i++);
	for(j=i+1;j<=N&&S[j]==T[j];j++);
	if(S[i]==S[j]&&T[i]==T[j]) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}