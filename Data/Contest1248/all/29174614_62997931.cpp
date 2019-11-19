#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#define NM 600015
#define INF 2e18
#define MOD 1000000007
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define si(n) fscanf(in,"%d",&n)
#pragma warning(disable:4996)
typedef long long int ll;
using namespace std;

//FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
//FILE *in = fopen("input.txt", "r"), *out = stdout;
FILE *in = stdin, *out = stdout;

int n, st, cnt[NM];
char a[NM];
void input() {
	fscanf(in, "%d\n", &n);
	fscanf(in, "%s", &a[1]);
}
void pro() {
	int minV = 100000, minIdx = 0;
	FOR(i, 1, n) {
		if (a[i] == '(') cnt[i] = cnt[i - 1] + 1;
		else cnt[i] = cnt[i - 1] - 1;
		if (minV > cnt[i]) minV = cnt[i], minIdx = i;
	}
	if (cnt[n] != 0) {
		fprintf(out, "0\n1 1");
		return;
	}
	FOR(i, 1, n) cnt[i] -= minV;
	FOR(i, n + 1, n * 2) cnt[i] = cnt[i - n];

	int res = 0;
	// ( ) -> ) (   , interval -= 2
	int zero = 0, ml = -1, mr = -1, cnt2 = 0, maxV = 0;
	FOR(i, 1, n) if (cnt[i] == 0) zero++;

	if (zero > maxV) {
		maxV = zero;
		ml = 1, mr = 1;
	}
	FOR(i, 1, n * 2) {
		if (cnt[i] == 1) {
			int l = i, cnt1 = 0;
			for (;;) {
				if (cnt[i] == 1) cnt1++;
				if (cnt[i + 1] == 0) break;
				i++;
			}
			int r = i + 1;
			if (maxV < cnt1) {
				maxV = cnt1;
				ml = l, mr = r;
			}
		}
	}

	FOR(i, 1, n * 2) {
		if (cnt[i] == 2) {
			int l = i, cnt2 = 0;
			for (;;) {
				if (cnt[i] == 2) cnt2++;
				if (cnt[i + 1] == 1) break;
				i++;
			}
			int r = i + 1;
			if (maxV < cnt2 + zero) {
				maxV = cnt2 + zero;
				ml = l, mr = r;
			}
		}
	}

	int one = 0;
	FOR(i, 1, n) if (cnt[i] == 1) one++;
	int leftZero = n+1, rightZero = 0;
	FOR(i, 1, n) {
		if (cnt[i] == 0) rightZero = max(rightZero, i), leftZero = min(leftZero, i);
	}
	FOR(i, leftZero, rightZero) if (cnt[i] == 1) one--;
	if (maxV < one) {
		maxV = one;
		ml = leftZero, mr = rightZero + 1;
	}

	if (ml > n) ml -= n;
	if (mr > n) mr -= n;
	fprintf(out, "%d\n%d %d", maxV, ml, mr);
}
int main() {
	input();
	pro();
	return 0;
}