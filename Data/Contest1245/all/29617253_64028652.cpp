#include<bits/stdc++.h>
using namespace std;
int a[1005], b[1005];
long long f[45][2][2];
long long calc(int n, int m) {
	if(n < 0 || m < 0) return 0;
	int lim = 40;
	for(int i = 1; i <= lim; i ++) a[lim - i + 1] = n % 2, n /= 2;
	for(int i = 1; i <= lim; i ++) b[lim - i + 1] = m % 2, m /= 2;
	memset(f, 0, sizeof f);
	f[1][1][1] = 1;
	for(int i = 1; i < lim; i ++) {
		for(int k0 = 0; k0 <= 1; k0 ++) {
			for(int k1= 0; k1 <= 1; k1 ++) if(f[i][k0][k1]){
				if(k0 == 0) {
					if(k1 == 0) {
						f[i + 1][k0][k1] += 3ll * f[i][k0][k1];
					} else {
						if(b[i + 1]) {
							f[i + 1][k0][0] += 2ll * f[i][k0][k1];
							f[i + 1][k0][1] += f[i][k0][k1];
						} else {
							f[i + 1][k0][k1] += 2ll * f[i][k0][k1];
						}
					}
				} else {
					if(a[i + 1]) { //printf("*");
						if(k1 == 0) {
							f[i + 1][0][k1] += 2 * f[i][k0][k1];
							f[i + 1][1][k1] += f[i][k0][k1];
						} else {
							if(b[i + 1]) {
								f[i + 1][0][0] += f[i][k0][k1];
								f[i + 1][0][1] += f[i][k0][k1];
								f[i + 1][1][0] += f[i][k0][k1];
							} else {
								f[i + 1][0][k1] +=  f[i][k0][k1];
								f[i + 1][1][k1] +=  f[i][k0][k1];
							}
						}
					} else {
						if(k1 == 0) {
							f[i + 1][1][k1] += 2ll * f[i][k0][k1];
						} else {
							if(b[i + 1]) {
								f[i + 1][1][0] += f[i][k0][k1];
								f[i + 1][1][1] += f[i][k0][k1];
							} else {
								f[i + 1][1][k1] +=  f[i][k0][k1];
							}
						}
					}
					
				}
			}
		}
	}
/*	for(int i = 1; i <= lim; i ++) printf("%d ", a[i]); printf("\n");
	for(int i = 1; i <= lim; i ++) printf("%d ", b[i]); printf("\n");
	for(int i = 1; i <= lim; i ++) printf("%d ", f[i][0][0]); printf("\n");
	for(int i = 1; i <= lim; i ++) printf("%d ", f[i][0][1]); printf("\n");
	for(int i = 1; i <= lim; i ++) printf("%d ", f[i][1][0]); printf("\n");
	for(int i = 1; i <= lim; i ++) printf("%d ", f[i][1][1]); printf("\n");*/
	return f[lim][0][0] + f[lim][0][1] + f[lim][1][0] + f[lim][1][1];
}
int main() {
	int t;
	scanf("%d", &t);
	while(t --) {
		int l, r;
		scanf("%d%d", &l, &r);
	//	printf("%I64d", calc(4, 4));
		printf("%I64d\n", calc(r, r) - calc(l - 1, r) * 2 + calc(l - 1, l - 1));	
	}
	
	return 0;
}

