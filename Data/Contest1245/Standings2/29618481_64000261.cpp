#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const ll MOD = (ll)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;

// 어떻게 내는 게 이득이지?
char s[101];
int win[101];

int main() {
	int t;
	scanf("%d", &t); 

	while (t--) {
		int n;
		scanf("%d", &n);
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		scanf("%s", s); 

		memset(win, 0, sizeof(win));

		vector<char> ans;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'R' && b) win[i] = 1, b--;
			if (s[i] == 'P' && c) win[i] = 1, c--;
			if (s[i] == 'S' && a) win[i] = 1, a--;
		}

		int tt = a + b + c;
		// n/2번까지는 질 수 있음.
		if (n / 2 < tt) printf("NO\n");
		else {
			printf("YES\n");
			for (int i = 0; i < n; i++) {
				if (win[i] == 1) {
					if (s[i] == 'R') printf("P");
					else if (s[i] == 'P') printf("S");
					else printf("R");
				}
				else {
					if (a) a--, printf("R");
					else if (b) b--, printf("P");
					else c--, printf("S");
				}
			}
			printf("\n");
		}
	}
}