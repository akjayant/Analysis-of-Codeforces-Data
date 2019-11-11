#include <cstdio>
#include <algorithm>
#include <utility>

#define FOR(i, n) for(int i = 0; i < n; i++) 

#define pow CHANGETHENAMESTUPID

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

void load() {

}

bool solve() {
	int n, a, b, c; scanf("%d%d%d%d", &n, &a, &b, &c);
	char s[n+1]; scanf("%s", s);
	int a_ = 0, b_ = 0, c_ = 0;
	FOR(i, n) {
		switch(s[i]) {
			case 'R':
				a_++;
				break;
			case 'S':
				c_++;
				break;
			case 'P':
				b_++;
				break;
		}
	}
	int pob = min(a, c_) + min(b, a_) + min(c, b_);
	if (pob < (n+1)/2) return false;
	char t[n+1];
	fill(t, t+n, 0);
	FOR(i, n) {
		if (s[i] == 'R') {
			if (b) {
				t[i] = 'P';
				b--;
			}
		} else if (s[i] == 'P') {
			if (c) {
				t[i] = 'S';
				c--;
			}
		} else {
			if (a) {
				t[i] = 'R';
				a--;
			}
		}
	}
	FOR(i, n) {
		if (!t[i]) {
			if (a) {
				t[i] = 'R'; a--;
			} else if (b) {
				t[i] = 'P'; b--;
			} else {
				t[i] = 'S'; c--;
			}
		}
	}
	t[n] = 0;
	printf("YES\n%s\n", t);
	return true;
}

int main() {
	int t; scanf("%d", &t); while (t--) {
	load();
	if (!solve()) printf("NO\n");
	}
	return 0;
}
