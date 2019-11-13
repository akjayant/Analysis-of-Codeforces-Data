#include<stdio.h>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;
#define M 1000000007
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
int n, m;
char a[1000009];
int d[1000009];
int main() {
	int i, j, k;
	int t;
	scanf("%s", a);
	for (n = 0; a[n]; n++);
	for (i = 0; i < n; i++) {
		if (a[i] == 'm')break;
		if (a[i] == 'w')break;
	}
	if (i < n) {
		printf("0\n");
	}
	else {
		d[0] = 1;
		for (i = 1; i <= n; i++) {
			d[i] = d[i - 1];
			if (i >= 2 && a[i - 1] == 'n' && a[i - 2] == 'n')
				d[i] = (d[i] + d[i - 2]) % M;
			if (i >= 2 && a[i - 1] == 'u' && a[i - 2] == 'u')
				d[i] = (d[i] + d[i - 2]) % M;
		}
		printf("%d\n", d[n]);
	}
}