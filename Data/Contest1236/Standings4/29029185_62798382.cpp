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

const int MXN = 310;
const int C = 262144;
const int INF = 1000000001;

VI grupa[MXN];

void test() {
    int n;
    scanf("%d", &n);
    int k = n / 2;
    if(n % 2 == 0) {
        int iter = 1;
        FOR(i, 1, 2 * k)
            FOR(j, 1, k)
                grupa[i].PB(iter++);
        FORD(i, 2 * k, 1)
            FOR(j, 1, k)
                grupa[i].PB(iter++);
    }
    else {
        int iter = 1;
        FOR(i, 1, 2 * k + 1)
            FOR(j, 1, k)
                grupa[i].PB(iter++);
        FORD(i, 2 * k + 1, 1)
            FOR(j, 1, k)
                grupa[i].PB(iter++);
        FOR(i, 1, 2 * k + 1)
            grupa[i].PB(iter++);
    }
    FOR(i, 1, n) {
        FOREACH(it, grupa[i])
            printf("%d ", *it);
        printf("\n");
    }
}

int main() {
	int te = 1;
//	scanf("%d", &te);
	while(te--)
		test();
	return 0;
}

