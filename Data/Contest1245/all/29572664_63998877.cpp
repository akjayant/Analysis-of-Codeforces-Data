#include<stdio.h>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
int n, m;
int p[3];
char xx[1009];
int a[1009];
int b[1009];
int ctoi(char x) {
	if (x == 'R')return 0;
	if (x == 'P')return 1;
	if (x == 'S')return 2;
	return -1;
}
char itoc(int x) {
	if (x == 0)return 'R';
	if (x == 1)return 'P';
	if (x == 2)return 'S';
	return ' ';
}
int main() {
	int i, j, k;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < 3; i++)scanf("%d", &p[i]);
		scanf("%s", xx);
		for (i = 0; i < n; i++) {
			a[i] = ctoi(xx[i]);
			b[i] = -1;
		}
		m = 0;
		for (i = 0; i < n; i++) {
			j = (a[i] + 1) % 3;
			if (p[j] > 0) {
				p[j]--;
				b[i] = j;
				m++;
			}
		}
		if (m >= (n+1) / 2) {
			printf("YES\n");
			for (i = 0; i < n; i++) {
				if (b[i] == -1) {
					for (j = 0; j < 3; j++) {
						if (p[j] > 0) {
							p[j] --;
							b[i] = j;
							break;
						}
					}
				}
				printf("%c", itoc(b[i]));
			}
			printf("\n");
		}
		else {
			printf("NO\n");
		}
	}
}