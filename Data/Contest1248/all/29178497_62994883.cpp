// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
 
#define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl;
#define fastIO std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
 
typedef long long ll;
typedef long double ld;
 
std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
 
const double PI = atan2(0., -1.);
const int INF = 0x3f3f3f3f;
const int N = 1 << 19;
 
int n;
char str[N];
int bal[N];
int q[N];
 
int getAns() {
	for (int i = 0; i <= 3 * n; ++i) {
		bal[i] = 0;
		q[i] = 0;
	}
 
	// std::map<int, int> q;
 
	for (int i = 0; i < n; ++i) {
		bal[i + 1] += bal[i];
 
		if (str[i] == '(') {
			++bal[i + 1];
		} else {
			--bal[i + 1];
		}
	}
 
	if (bal[0] != bal[n]) {
		return 0;
	}
 
	for (int i = 0; i < n; ++i) {
		++q[bal[i] + n];
	}
 
 	for (int i = 0; i < N; ++i) {
 		if (q[i] != 0) {
 			return q[i];
 		}
 	}

 	throw 228;
	// return q.begin()->second;
}
 
int main(void) {
	scanf("%d\n%s", &n, str);
 
	int ans = getAns();
	int fi = 0;
	int se = 0;
 
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (str[i] != str[j]) {
				std::swap(str[i], str[j]);
 
				int curAns = getAns();
				if (curAns > ans) {
					ans = curAns;
					fi = i;
					se = j;
				}
 
				std::swap(str[i], str[j]);
			}
		}
	}	
 
	printf("%d\n%d %d\n", ans, fi + 1, se + 1);
 
	return 0;
}