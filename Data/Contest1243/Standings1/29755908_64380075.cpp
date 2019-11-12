#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 10000 + 100;
int T, n, cnt;
int dif[maxn];
char s[maxn], t[maxn];

int main() {
	ios::sync_with_stdio(false);

	scanf("%d", &T);
	while(T--) {
		cnt = 0;
		scanf("%d", &n);
		scanf("%s%s", s, t);
		for(int i = 0; i < n; ++i) {
			if(s[i] != t[i]) {
				dif[cnt++] = i;
			}
		}
		if(cnt == 0) {
			printf("Yes\n");
			continue;
		}
		if(cnt == 2) {
			if(s[dif[0]] == s[dif[1]] && t[dif[0]] == t[dif[1]]) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
			continue;
		}
		printf("No\n");
	}

    return 0;
}