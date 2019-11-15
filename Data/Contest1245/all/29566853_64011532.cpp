#define _USE_MATH_DEFINES
#include <cmath>
#include <stdio.h>
#include <vector>
#include <set>
#include <stack>
#include <cstring>
#include <algorithm>

#define rep(a,b,c) for(int a=b;a<c;a++)
#define i(a) scanf("%d",&a)
#define l(a) scanf("%lld",&a)
#define INF 1000000000
typedef long long ll;
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main(){
	int t;
	i(t);
	while (t--) {
		int n; i(n);
		int a, b, c; i(a); i(b); i(c); getchar();
		int r = 0; int p = 0; int s = 0;
		int* ar= new int[n+1];
		rep(i, 0, n) {
			char d = getchar();
			if (d == 'R') {
				r++; ar[i] = 0;
			}
			else if (d == 'P') {
				p++; ar[i] = 1;
			}
			else {
				s++; ar[i] = 2;
			}
		}
		int win = min(a, s) + min(b, r) + min(c, p);
		if (win < (n + 1) / 2) {
			printf("NO\n"); continue;
		}
		printf("YES\n");
		int cnt[3] = { a,b,c };
		int cnt2[3] = { a - s,b - r,c - p };
		char ck[3] = { 'R','P','S' };
		rep(i, 0, n) {
			char k;
			int j = (ar[i] + 1) % 3;
			if (cnt[j] > 0) {
				k = ck[j];
				cnt[j]--;
			}
			else {
				rep(l, 1, 3) {
					j++; j %= 3;
					if (cnt2[j] > 0) {
						k = ck[j];
						cnt2[j]--;
						break;
					}
				}
			}
			printf("%c", k);
		}
		printf("\n");
	}
}