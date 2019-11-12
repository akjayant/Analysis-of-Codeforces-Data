#include <bits/stdc++.h>
#define fi first
#define se second
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

int N, Q;
int ar[1010];
int main()
{
	scanf("%d", &Q);
	int i;
	while (Q--) {
		scanf("%d", &N);
		for (i=0; i<N; i++) scanf("%d", &ar[i]);
		sort(ar, ar+N);
		reverse(ar, ar+N);
		int mx=0;
		for (i=0; i<N; i++) mx=max(mx, min(i+1, ar[i]));
		printf("%d\n", mx);
	}
	return 0;
}