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
char s1[10010], s2[10010];
int main()
{
	scanf("%d", &Q);
	int i, j;
	while (Q--) {
		scanf("%d %s %s", &N, s1, s2);
		for (i=0, j=0; i<N; i++) if (s1[i]!=s2[i]) j++;
		if (j==0) puts("Yes");
		else if (j==2) {
			for (i=0; i<N; i++) if (s1[i]!=s2[i]) break;
			for (j=i+1; j<N; j++) if (s1[j]!=s2[j]) break;
			if (s1[i]==s1[j]&&s2[i]==s2[j]) puts("Yes");
			else puts("No");
		}
		else puts("No");
	}
	return 0;
}