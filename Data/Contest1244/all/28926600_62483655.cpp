#include <cstdio>

const int MAXN = 1000010;
int n, x[MAXN];
bool v[MAXN];
long long k, cur = 0;

int main() {
	// freopen("Temp.in", "r", stdin);
	// freopen("Temp.out", "w", stdout);

	scanf("%d %I64d", &n, &k);
	cur = static_cast<long long>(n + 1) * n >> 1;

	if (cur > k) {
		puts("-1");
		return 0;
	}

	for (int i = 1, j = n; i <= n; i++) {
		while (j > 0 && j - i > k - cur)
			j --;
		if (j <= i)
			break;
		// printf("%d => %d\n", i, j);
		cur += j - i;
		x[i] = j;
		v[j] = true;
		j --;
	}

	for (int i = 1, j = 1; i <= n; i++) {
		if (x[i])
			continue;
		while (v[j])
			j ++;
		x[i] = j ++;
	}

	printf("%I64d\n", cur);
	for (int i = 1; i <= n; i++)
		printf("%d ", i);
	puts("");
	for (int i = 1; i <= n; i++)
		printf("%d ", x[i]);
	puts("");

	return 0;
}
