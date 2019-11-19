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

int n;
ll a[NM];
void input() {
	si(n);
	FOR(i, 1, n) fscanf(in, "%lld", &a[i]);
}
void pro() {
	sort(a + 1, a + 1 + n);
	ll h = 0, v = 0;
	FOR(i, 1, n / 2) h += a[i];
	FOR(i, n/2+1, n) v += a[i];
	fprintf(out, "%lld", v*v + h * h);
}
int main() {
	input();
	pro();
	return 0;
}