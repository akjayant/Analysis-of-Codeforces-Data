#include <bits/stdc++.h>

using namespace std;

#define sc(a) scanf("%d",&a)
#define sc2(a,b) sc(a), sc(b)
#define sc3(a,b,c) sc2(a, b), sc(c)
#define pri(x) printf("%d\n",x)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define BUFF ios::sync_with_stdio(0)
#define prif() printf("\n")
#define prie(x) printf("%d ", x)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10, MOD = 1e9+7;
char s[MAX];
ll dp[MAX];
int n;

ll solve(int i) {
	if (i == n) return 1;
	auto& x = dp[i];
	if (x+1) return x;
	if (s[i] != 'u' and s[i] != 'n') return x=solve(i+1);
	if (s[i] != s[i+1]) return x=solve(i+1);
	return x=(solve(i+1)+solve(i+2))%MOD;
}

int main() {
	scanf(" %s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++) if (s[i] == 'm' or s[i] == 'w') return !printf("0\n");
	for (int i = 0; i < n; i++) dp[i] = -1;
	printf("%lld\n", solve(0));
	exit(0);
}
