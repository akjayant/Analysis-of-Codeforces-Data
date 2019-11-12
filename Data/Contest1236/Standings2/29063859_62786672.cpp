/*
ID: espr1t
TASK: 
KEYWORDS: 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
FILE* in = stdin; FILE* out = stdout;

const int MAX = 1024;
const int MOD = 1000000007;

int fastPow(int num, int pwr) {
    int ret = 1;
    while (pwr) {
        if (pwr & 1)
            ret = ((long long)ret * num) % MOD;
        num = ((long long)num * num) % MOD;
        pwr >>= 1;
    }
    return ret;
}

int main(void) {
//	in = fopen("B.in", "rt");
	
	int n, m;
	fscanf(in, "%d %d", &n, &m);
	int ans = fastPow(2, m) - 1;
	if (ans < 0) ans += MOD;
	ans = fastPow(ans, n);
	fprintf(out, "%d\n", ans);
	
	return 0;
}
