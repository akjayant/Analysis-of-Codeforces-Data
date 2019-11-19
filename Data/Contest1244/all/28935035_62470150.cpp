#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long

const int N = 1e3+11;
int t, n;
char a[N];

int main() {
	cin >> t;
	while (t > 0) {
		t--;
		scanf("%d", &n);
		int l=n, r=-1;
		for (int i=0;i<n;i++) {
			scanf(" %c", &a[i]);
			if (a[i] == '1') {
				l = min(l, i);
				r = max(r, i);
			}
		}
		int res = n;
		res = max(res, (r+1)+(r+1));
		res = max(res, (n-l)+(n-l));
		printf("%d\n", res);
	}
	return 0;
}