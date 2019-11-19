#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>

const int MAXN = 100100;
const int MOD = 1000000007;

int MyGCD(int a, int b) {
	if(b) return MyGCD(b, a % b);
	return a;
}

long long ModPow(long long x, long long y, long long z) {
	x %= z;
	long long ans = 1;
	while(y) {
		if(y & 1) ans = ans * x % z;
		x = x * x % z;
		y >>= 1;
	}
	return ans;
}

class C_Edge {
public:
	friend bool operator<(const C_Edge &x, const C_Edge &y) {
		return x.cost > y.cost;
	}

	int u, v;
	long long cost;
} tmp, tmp2;

int n;
bool unvis[MAXN];

int MyAbs(const int& x) {
	if(x < 0) return -x;
	return x;
}

char s[MAXN];
long long x[MAXN], y[MAXN], c[MAXN], k[MAXN];
std::vector< int > pp;
std::vector< std::pair< int, int > > qq;

long long Prim(int st) {
	long long ans = 0;
	std::priority_queue< C_Edge > q;
	tmp.u = tmp.v = st;
	tmp.cost = c[st];
	q.push(tmp);
	memset(unvis, true, sizeof(unvis));
	while(!q.empty()) {
		tmp = q.top();
		q.pop();
		if(!unvis[tmp.v]) continue;
		unvis[tmp.v] = false;
		ans += tmp.cost;
		if(tmp.cost == c[tmp.v]) pp.push_back(tmp.v);
		else qq.push_back(std::make_pair(tmp.u, tmp.v));
		tmp2.u = tmp.v;
		for(int i = 1; i <= n; ++i)
			if(unvis[i]) {
				tmp2.v = i;
				tmp2.cost = std::min(c[i], (MyAbs(x[tmp.v] - x[i]) + MyAbs(y[tmp.v] - y[i])) * (k[tmp.v] + k[i]));
				q.push(tmp2);
			}
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i  = 1; i <= n; ++i) scanf("%lld%lld", x + i, y + i);
	int st = 1;
	for(int i  = 1; i <= n; ++i) {
		scanf("%lld", c + i);
		if(c[i] < c[st]) st = i;
	}
	for(int i  = 1; i <= n; ++i) scanf("%lld", k + i);
	printf("%lld\n", Prim(st));
	printf("%lu\n", pp.size());
	bool space_flag = false;
	for(int i : pp) {
		if(space_flag) printf(" ");
		else space_flag = true;
		printf("%d", i);
	}
	printf("\n%lu\n", qq.size());
	for(int i = 0; i < qq.size(); ++i) printf("%d %d\n", qq[i].first, qq[i].second);
	return 0;
}