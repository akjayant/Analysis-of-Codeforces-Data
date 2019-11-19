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

int solve()
{
	int n; scanf("%d", &n);
	char s[n+1];
	scanf("%s", s);
	int mini = n, maxi = -1;
	FOR(i, n) {
		if (s[i] == '1') {
			mini = min(mini, i);
			maxi = max(maxi, i);
		}
	}
	if (maxi == -1) return n;
	int sol = 0;
	auto check = [&](int x) {
		sol = max(sol, x);
	};
	check((maxi+1)*2);
	check((n-mini)*2);
	check(n);
	return sol;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        load();
        printf("%d\n", solve());
    }
    return 0;
}
