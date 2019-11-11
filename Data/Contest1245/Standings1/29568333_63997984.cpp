#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
using namespace std;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int main()
{
	#ifdef DEBUG
	freopen("text.in", "r", stdin);
	#endif
	int t, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		if (gcd(a, b) == 1)
			puts("Finite");
		else
			puts("Infinite");
	}
	return 0;
}