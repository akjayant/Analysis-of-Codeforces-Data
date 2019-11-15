#include <bits/stdc++.h>
#define fi first
#define se second
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

int N, Q;
char s1[55], s2[55];
int cnt[26];
int stk[55][2], tp;
int main()
{
	scanf("%d", &Q);
	int i, j;
	while (Q--) {
		memset(cnt, 0, sizeof(cnt)); tp=0;
		scanf("%d %s %s", &N, s1, s2);
		for (i=0; i<N; i++) {
			cnt[s1[i]-'a']++;
			cnt[s2[i]-'a']++;
		}
		for (i=0; i<26; i++) if (cnt[i]%2) {
			puts("No");
			break;
		}
		if (i<26) continue;
		puts("Yes");
		for (i=0; i<N; i++) {
			if (s1[i]==s2[i]) continue;
			for (j=i+1; j<N; j++) if (s1[i]==s1[j]) break;
			if (j<N) {
				stk[tp][0]=j; stk[tp][1]=i; tp++;
				swap(s1[j], s2[i]);
				continue;
			}
			for (j=i+1; j<N; j++) if (s1[i]==s2[j]) break;
			stk[tp][0]=i+1; stk[tp][1]=j; tp++;
			swap(s1[i+1], s2[j]);
			stk[tp][0]=i+1; stk[tp][1]=i; tp++;
			swap(s1[i+1], s2[i]);
		}
		if (tp==0) {
			printf("1\n1 1\n");
		}
		else {
			printf("%d\n", tp);
			for (i=0; i<tp; i++) printf("%d %d\n", stk[i][0]+1, stk[i][1]+1);
		}
	}
	return 0;
}