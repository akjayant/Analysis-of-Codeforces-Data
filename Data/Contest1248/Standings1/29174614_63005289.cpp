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

int n, m, dy[NM][2];
void input() {
	si(n), si(m);
}
void pro() {
	dy[1][0] = 1, dy[1][1] = 1;
	dy[2][0] = 2, dy[2][1] = 2;
	FOR(i, 3, 100000) {
		dy[i][0] = dy[i - 1][1] + dy[i - 2][1];
		dy[i][0] %= MOD;
		dy[i][1] = dy[i - 1][0] + dy[i - 2][0];
		dy[i][1] %= MOD;
	}
	ll ans = 0;
	ans += dy[n][0] + dy[n][1];
	ans += dy[m][0] + dy[m][1];
	ans -= 2;
	ans %= MOD;
	fprintf(out, "%lld", ans);
}
int main() {
	input();
	pro();
	return 0;
}