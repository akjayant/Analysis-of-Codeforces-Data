#include<bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) (int)(x).size()
#define CLEAR(tab) memset(tab, 0, sizeof(tab))
#define REP(x, n) for(int x = 0; x < (n); x++)
#define FOR(x, b, e) for(int x = (b); x <= (e); x++)
#define FORD(x, b, e) for(int x = (b); x >= (e); x--)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define DEBUG(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MXN = 1000010;
const int C = 262144;
const int INF = 1000000001;
const int MOD = 1000000007;

int pot(int x, int n) {
    int xx = x;
    int res = 1;
    while(n) {
        if(n % 2)
            res = (LL)res * xx % MOD;
        xx = (LL)xx * xx % MOD;
        n /= 2;
    }

    return res;
}

void test() {
    int n, m;
    scanf("%d %d", &n, &m);
    int res = pot(2, m);
    res = (res + MOD - 1) % MOD;
    res = pot(res, n);
    printf("%d\n", res);
}

int main() {
	int te = 1;
//	scanf("%d", &te);
	while(te--)
		test();
	return 0;
}

