#include <cstdio>
#include <algorithm>

#define R register
int T, N, a, b, c;
char s[110], t[110];

//r p s

int main() {
	for(scanf("%d", &T); T--; ) {
		scanf("%d%d%d%d%s", &N, &a, &b, &c, s);
		R int x = 0, y = 0, z = 0;
		for(R int i = 0; i < N; ++i) {
			if(s[i] == 'R') ++x;
			if(s[i] == 'P') ++y;
			if(s[i] == 'S') ++z;
		}
		R int res; 
		res = std::min(x, b) + std::min(y, c) + std::min(z, a);
		if(res < (N + 1) / 2) {puts("NO"); continue; }
		puts("YES");
		for(R int i = 0; i < N; ++i) t[i] = 0;
		for(R int i = 0; i < N; ++i) {
			if(s[i] == 'P') if(c) t[i] = 'S', --c;
			if(s[i] == 'R') if(b) t[i] = 'P', --b;
			if(s[i] == 'S') if(a) t[i] = 'R', --a;
		}
		for(R int i = 0; i < N; ++i) {
			if(!t[i]) {
				if(a) t[i] = 'R', --a;
				else if(b) t[i] = 'P', --b;
				else t[i] = 'S', --c;
			}
		}
		for(R int i = 0; i < N; ++i) printf("%c", t[i]); puts("");
	}
	return 0;
}
