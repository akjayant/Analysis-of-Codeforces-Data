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

int t, a, b, c, d, k;

int main() {
	cin >> t;
	while (t > 0) {
		t--;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int stopp = 0;
		for (int i=0;i<=k;i++) {
			int x = i;
			int y = k-i;
			if (x*c >= a && y * d >= b) {
				printf("%d %d\n", x, y);
				stopp++;
				break;
			}
		}
		if (stopp == 0) printf("%d\n", -1);
	}
	return 0;
}