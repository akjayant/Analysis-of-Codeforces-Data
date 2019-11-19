#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll c1[100005];
ll c2[100005];
ll c3[100005];

vector <int> v[100005];
vector <int> k;

int col1[100005];
int col2[100005];
int col3[100005];
int col4[100005];
int col5[100005];
int col6[100005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i=1 ; i<=n ; i++) scanf("%I64d", c1+i);
	for (int i=1 ; i<=n ; i++) scanf("%I64d", c2+i);
	for (int i=1 ; i<=n ; i++) scanf("%I64d", c3+i);
	for (int i=0 ; i<n-1 ; i++) {
		int x,y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
		if (v[x].size()>2 or v[y].size()>2) {
			printf("-1\n");
			return 0;
		}
	}
	int pos = 0;
	for (int i=1 ; i<=n ; i++) {
		if (v[i].size() == 1) {
			pos = i;
			break;
		}
	}
	int l = -1;
	for (int i=0 ; i<n ; i++) {
		k.push_back(pos);
//		printf("%d-", pos);
		int nxt = 0;
		for (int i=0 ; i<v[pos].size() ; i++) {
			if (v[pos][i] == l) continue;
			nxt = v[pos][i];
		}
		l = pos;
		pos = nxt;
	}
//	printf("\n");
	ll sol1 = 0;
	ll sol2 = 0;
	ll sol3 = 0;
	ll sol4 = 0;
	ll sol5 = 0;
	ll sol6 = 0;
	for (int i=0 ; i<n ; i++) {
		if (i%3 == 0) {
			sol1 += c1[k[i]];
			sol2 += c1[k[i]];
			sol3 += c2[k[i]];
			sol4 += c2[k[i]];
			sol5 += c3[k[i]];
			sol6 += c3[k[i]];

			col1[k[i]] = 1;
			col2[k[i]] = 1;
			col3[k[i]] = 2;
			col4[k[i]] = 2;
			col5[k[i]] = 3;
			col6[k[i]] = 3;
		}
		if (i%3 == 1) {
			sol1 += c2[k[i]];
			sol2 += c3[k[i]];
			sol3 += c1[k[i]];
			sol4 += c3[k[i]];
			sol5 += c1[k[i]];
			sol6 += c2[k[i]];

			col1[k[i]] = 2;
			col2[k[i]] = 3;
			col3[k[i]] = 1;
			col4[k[i]] = 3;
			col5[k[i]] = 1;
			col6[k[i]] = 2;
		}
		if (i%3 == 2) {
			sol1 += c3[k[i]];
			sol2 += c2[k[i]];
			sol3 += c3[k[i]];
			sol4 += c1[k[i]];
			sol5 += c2[k[i]];
			sol6 += c1[k[i]];

			col1[k[i]] = 3;
			col2[k[i]] = 2;
			col3[k[i]] = 3;
			col4[k[i]] = 1;
			col5[k[i]] = 2;
			col6[k[i]] = 1;
		}
	}
	ll b = min(min(sol1, min(sol2, sol3)), min(sol4, min(sol5, sol6)));
	printf("%I64d\n", b);
	if (sol1 == b) {
		for (int i=1 ; i<=n ; i++) {
			printf("%d ", col1[i]);
		}
		printf("\n");
		return 0;
	}
	if (sol2 == b) {
		for (int i=1 ; i<=n ; i++) {
			printf("%d ", col2[i]);
		}
		printf("\n");
		return 0;
	}
	if (sol3 == b) {
		for (int i=1 ; i<=n ; i++) {
			printf("%d ", col3[i]);
		}
		printf("\n");
		return 0;
	}
	if (sol4 == b) {
		for (int i=1 ; i<=n ; i++) {
			printf("%d ", col4[i]);
		}
		printf("\n");
		return 0;
	}
	if (sol5 == b) {
		for (int i=1 ; i<=n ; i++) {
			printf("%d ", col5[i]);
		}
		printf("\n");
		return 0;
	}
	if (sol6 == b) {
		for (int i=1 ; i<=n ; i++) {
			printf("%d ", col6[i]);
		}
		printf("\n");
		return 0;
	}
	return 0;
}