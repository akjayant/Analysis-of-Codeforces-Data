#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d",&a)
#define sc2(a,b) sc(a), sc(b)
#define sc3(a,b,c) sc2(a, b), sc(c)
#define pri(x) printf("%d\n",x)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define BUFF ios::sync_with_stdio(0)
#define prif() printf("\n")
#define prie(x) printf("%d ", x)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

char s[200], ans[200];

int main() {
	int t; sc(t);
	while (t--) {
		int n; sc(n);
		int a, b, c; sc3(a, b, c);
		int A = 0, B = 0, C = 0;
		scanf(" %s", s);
		for (int i = 0; i < n; i++) {
			if (s[i] == 'R') A++;
			if (s[i] == 'P') B++;
			if (s[i] == 'S') C++;
		}
		int win = min(a, C)+min(b, A)+min(c, B);
		if (win < (n+1)/2) printf("NO\n");
		else {
			printf("YES\n");
			for (int i = 0; i < n; i++) ans[i] = 'o';
			for (int i = 0; i < n; i++) if (s[i] == 'R' and b) {
				b--;
				ans[i] = 'P';
			}
			for (int i = 0; i < n; i++) if (s[i] == 'P' and c) {
				c--;
				ans[i] = 'S';
			}
			for (int i = 0; i < n; i++) if (s[i] == 'S' and a) {
				a--;
				ans[i] = 'R';
			}
			for (int i = 0; i < n; i++) if (ans[i] == 'o') {
				if (a) {
					ans[i] = 'R';
					a--;
				} else if (b) {
					ans[i] = 'P';
					b--;
				} else {
					ans[i] = 'S';
					c--;
				}
			}
			for (int i = 0; i < n; i++) printf("%c", ans[i]);
			prif();
		}
	}
	exit(0);
}
