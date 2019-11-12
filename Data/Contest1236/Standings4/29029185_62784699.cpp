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

const int MXN = 110;
const int C = 262144;
const int INF = 1000000001;

int dp[MXN][MXN][MXN];

void test() {
    int n = 101;
    FOR(i, 0, n)
        FOR(j, 0, n)
            FOR(k, 0, n) {
                if(i >= 1 && j >= 2)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 2][k] + 3);
                if(j >= 1 && k >= 2)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 2] + 3);
            }
    int t;
    scanf("%d", &t);
    FOR(i, 1, t) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", dp[a][b][c]);
    }
}

int main() {
	int te = 1;
//	scanf("%d", &te);
	while(te--)
		test();
	return 0;
}

