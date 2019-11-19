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

int n;
int a[MXN];

void test() {
    scanf("%d", &n);
    FOR(i, 1, n)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    LL res = 0;
    int posX = 0;
    int posY = 0;
    FORD(i, n, 1) {
        if(i > n / 2)
            posX += a[i];
        else
            posY += a[i];
    }
    cout<<(LL)posX * posX + (LL)posY * posY<<endl;
}

int main() {
	int te = 1;
//	scanf("%d", &te);
	while(te--)
		test();
	return 0;
}

