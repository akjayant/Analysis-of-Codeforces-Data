#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;

char s[101], ans[101];

int main()
{
	int tc; for(scanf("%d", &tc); tc--;){
		int N, A, B, C; scanf("%d %d %d %d %s", &N, &A, &B, &C, s);
		int a = 0, b = 0, c = 0;
		for(int i = 0; i < N; i++){
			if(s[i] == 'R') a++;
			else if(s[i] == 'P') b++;
			else c++;
		}

		if(min(a, B) + min(b, C) + min(c, A) < (N + 1) / 2){
			printf("NO\n");
			continue;
		}

		for(int i = 0; i < N; i++){
			if(s[i] == 'R' && B) ans[i] = 'P', B--;
			else if(s[i] == 'P' && C) ans[i] = 'S', C--;
			else if(s[i] == 'S' && A) ans[i] = 'R', A--;
			else ans[i] = 0;
		}
		for(int i = 0; i < N; i++){
			if(ans[i]) continue;
			if(A) ans[i] = 'R', A--;
			else if(B) ans[i] = 'P', B--;
			else ans[i] = 'S', C--;
		}
		
		ans[N] = 0;
		printf("YES\n%s\n", ans);
	}
	return 0;
}