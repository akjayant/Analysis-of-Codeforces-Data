#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		std::vector<int> p(n);
		long long npo = 0, npe = 0;
		for (int&  x : p) {
			scanf("%d", &x);
			if (x % 2 == 0) {
				++npe;
			} else {
				++npo;
			}
		}
		int m;
		scanf("%d", &m);
		std::vector<int> q(m);
		long long nqo = 0, nqe = 0;
		for (int& x : q) {
			scanf("%d", &x);
			if (x % 2 == 0) {
				++nqe;
			} else {
				++nqo;
			}
		}
		printf("%I64d\n", npo * nqo + npe * nqe);
	}
	return 0;
}