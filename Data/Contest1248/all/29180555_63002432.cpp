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

const int MXN = 100010;
const int C = 262144;
const int INF = 1000000001;
const int MOD = 1000000007;

LL D[MXN][4];
int n;

void test() {
    int n, m;
    scanf("%d %d", &n, &m);
    if(n < m)
        swap(n, m);
    FOR(i, 0, 3) {
        D[1][i] = 1;
        D[2][i] = 1;
    }
    D[1][1] = D[1][3] = 0;

    FOR(i, 3, max(n, m ) ) {
        D[i][0] = D[i - 1][2];
        D[i][1] = D[i - 1][0] + D[i - 1][2];
        D[i][2] = D[i - 1][3] + D[i - 1][1];
        D[i][3] = D[i - 1][1];
        FOR(j, 0, 3)
            D[i][j] %= MOD;
    }

    LL q = D[n][0] + D[n][1] + D[n][2] + D[n][3];
    q %= MOD;
    LL w = D[m][0] + D[m][1] + D[m][2] + D[m][3];
    w %= MOD;
    q = (q + w - 2 + MOD) % MOD;
    cout<<q<<endl;
}

int main() {
	int te = 1;
//	scanf("%d", &te);
	while(te--)
		test();
	return 0;
}

