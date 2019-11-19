#include <algorithm>
#include <cstdio>
#include <utility>

#define FOR(i, n) for (int i = 0; i < n; i++)

#define pow CHANGETHENAMESTUPID

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

void load()
{
}

void solve()
{
	int a, b, c, d, k;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
	int a_ = a / c;
	if (a % c != 0) a_++;
	int b_ = b / d;
	if (b % d != 0) b_++;
	if (a_ + b_ > k) {
		printf("-1\n");
		return;
	}
	printf("%d %d\n", a_, b_);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        load();
        solve();
    }
    return 0;
}
