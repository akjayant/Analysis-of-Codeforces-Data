#include <bits/stdc++.h>

using namespace std;

#define B 30

long long dp[B + 1][2][2][2];
int l, r;

long long solve(int b, bool lesser, bool greater, bool differ) { // Building (a, b) l <= a <= b <= r
	int bl, br;

	if (b == -1) {
		return differ ? 2 : 1;
	}

	if (dp[b][lesser][greater][differ] != -1) {
		return dp[b][lesser][greater][differ];
	}

	bl = (l >> b) & 1;
	br = (r >> b) & 1;
	dp[b][lesser][greater][differ] = 0;

	if (lesser and greater and differ) {
		dp[b][lesser][greater][differ] += solve(b - 1, true, true, true); // 00
		dp[b][lesser][greater][differ] += solve(b - 1, true, true, true); // 01
		dp[b][lesser][greater][differ] += solve(b - 1, true, true, true); // 10
	}
	else if (lesser and greater and !differ) {
		dp[b][lesser][greater][differ] += solve(b - 1, true, true, false); // 00
		dp[b][lesser][greater][differ] += solve(b - 1, true, true, true); // 01
	}
	else if (lesser and !greater and differ) {
		if (bl == 1) {
			dp[b][lesser][greater][differ] += solve(b - 1, true, false, true); // 10
		}
		else {
			dp[b][lesser][greater][differ] += solve(b - 1, true, false, true); // 00
			dp[b][lesser][greater][differ] += solve(b - 1, true, false, true); // 01
			dp[b][lesser][greater][differ] += solve(b - 1, true, true, true); // 10
		}
	}
	else if (lesser and !greater and !differ) {
		if (bl == 1) {
		}
		else {
			dp[b][lesser][greater][differ] += solve(b - 1, true, false, false); // 00
			dp[b][lesser][greater][differ] += solve(b - 1, true, false, true); // 01
		}
	}
	else if (!lesser and greater and differ) {
		if (br == 1) {
			dp[b][lesser][greater][differ] += solve(b - 1, true, true, true); // 00
			dp[b][lesser][greater][differ] += solve(b - 1, false, true, true); // 01
			dp[b][lesser][greater][differ] += solve(b - 1, true, true, true); // 10
		}
		else {
			dp[b][lesser][greater][differ] += solve(b - 1, false, true, true); // 00
			dp[b][lesser][greater][differ] += solve(b - 1, false, true, true); // 10
		}
	}
	else if (!lesser and greater and !differ) {
		if (br == 1) {
			dp[b][lesser][greater][differ] += solve(b - 1, true, true, false); // 00
			dp[b][lesser][greater][differ] += solve(b - 1, false, true, true); // 01
		}
		else {
			dp[b][lesser][greater][differ] += solve(b - 1, false, true, false); // 00
		}
	}
	else if (!lesser and !greater and differ) {
		if (bl == 1 and br == 1) {
			dp[b][lesser][greater][differ] += solve(b - 1, true, false, true); // 10
		}
		else if (bl == 1) {
			dp[b][lesser][greater][differ] += solve(b - 1, false, false, true); // 10
		}
		else if (br == 1) {
			dp[b][lesser][greater][differ] += solve(b - 1, true, false, true); // 00
			dp[b][lesser][greater][differ] += solve(b - 1, false, false, true); // 01
			dp[b][lesser][greater][differ] += solve(b - 1, true, true, true); // 10
		}
		else {
			dp[b][lesser][greater][differ] += solve(b - 1, false, false, true); // 00
			dp[b][lesser][greater][differ] += solve(b - 1, false, true, true); // 10
		}
	}
	else if (!lesser and !greater and !differ) {
		if (bl == 1 and br == 1) {
		}
		else if (bl == 1) {

		}
		else if (br == 1) {
			dp[b][lesser][greater][differ] += solve(b - 1, true, false, false); // 00
			dp[b][lesser][greater][differ] += solve(b - 1, false, false, true); // 01
		}
		else {
			dp[b][lesser][greater][differ] += solve(b - 1, false, false, false); // 00
		}
	}

	return dp[b][lesser][greater][differ];
}

int main() {
	int t;

	scanf("%d", &t);

	while (t--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d%d", &l, &r);
		printf("%lld\n", solve(B, false, false, false));
	}

	return 0;
}
