//#pragma GCC optimize(3)
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
typedef long long LL;
using namespace std;
#define MAXN 500005
#define eps (1e-11)
#define lyh 19260817
#define njj 19491001
#define pp 1000000007
const double pi = acos(-1.0);
#define P pair<int,int>
#define int LL

int c[MAXN];
int n;
int k[MAXN];
P poi[MAXN];
int answay[MAXN][2];
int ansbu[MAXN];
int vis[MAXN];
int cont1 = 0;
int cont2 = 0;
int tmpp[MAXN];

struct cmp {//定义结构来重载运算符
	bool operator ()(int &a, int &b) {
		return c[a] > c[b];//最小值优先
	}
};

priority_queue<int, vector<int>, cmp> q;

int gettop() {
	int minn = LLONG_MAX;
	int ind = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (minn >= c[i]) {
				ind = i;
				minn = c[i];
			}
		}
	}
	return ind;
}

int cost(int i, int j) {
	int dis = abs(poi[i].first - poi[j].first) + abs(poi[i].second - poi[j].second);
	return dis * (k[i] + k[j]);
}

signed main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%lld%lld", &x, &y);
		poi[i].first = x; poi[i].second = y;
	}
	for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &k[i]);
	for (int i = 1; i <= n; i++) q.push(i);
	int ans = 0;
	int count = 0;
	while (count<n) {
		int now = gettop();
		int tmp = c[now];
		bool flag = false;
		int tmpind = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) {
				if (tmp > cost(i, now)) {
					flag = true;
					tmp = cost(i, now);
					tmpind = i;
				}
			}
		}
		if ((!flag)&&tmpp[now]==0) {
			ansbu[cont1++] = now;
		}
		else {
			if (!flag) {
				answay[cont2][0] = now;
				answay[cont2][1] = tmpp[now];
				cont2++;
			}
			else {
				answay[cont2][0] = now;
				answay[cont2][1] = tmpind;
				cont2++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				if (c[i] > cost(i, now))tmpp[i] = now;
				c[i] = min(c[i], cost(i, now));
			}
		}
		vis[now] = true;
		ans += tmp;
		count++;
	}
	printf("%lld\n", ans);
	printf("%lld\n", cont1);
	for (int i = 0; i < cont1; i++) {
		printf("%lld ", ansbu[i]);
	}
	printf("\n");
	printf("%lld\n", cont2);
	for (int i = 0; i < cont2; i++) {
		printf("%lld %lld\n", answay[i][0], answay[i][1]);
	}
	return 0;
}