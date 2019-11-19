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

void pro() {
	int n, m;
	ll t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	si(n);
	FOR(i, 1, n) {
		int x; si(x);
		if (x % 2 == 0) t1++;
		else t2++;
	}
	si(m);
	FOR(i, 1, m) {
		int x; si(x);
		if (x % 2 == 0) t3++;
		else t4++;
	}
	fprintf(out, "%lld\n", t1*t3 + t2 * t4);
}
int main() {
	int TT; si(TT);
	FOR(tt, 1, TT) pro();
	return 0;
}