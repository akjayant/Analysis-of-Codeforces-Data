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
const int maxn = 100 + 100;
bool flag;
int T, n, len;
int cnt[maxn];
char s[maxn], t[maxn];
vector<pair<int, int> > ans;
bool vis[maxn];

int main() {
	ios::sync_with_stdio(false);

	scanf("%d", &T);
	while(T--) {
		flag = true;
		memset(cnt, 0, sizeof(int) * 26);
		scanf("%d", &n);
		scanf("%s%s", s, t);
		for(int i = 0; i < n; ++i) {
			++cnt[s[i] - 'a'];
			++cnt[t[i] - 'a'];
			if(s[i] == t[i]) {
				vis[i] = true;
			} else {
				vis[i] = false;
			}
		}
		for(int i = 0; i < 26; ++i) {
			if(cnt[i] % 2 == 1) {
				flag = false;
				break;
			}
		}
		if(!flag) {
			printf("No\n");
			continue;
		}
		ans.clear();
		for(int i = 0; i < n; ++i) {
			if(vis[i]) {
				continue;
			}
			for(int j = i + 1; j < n; ++j) {
				if(vis[j]) {
					continue;
				}
				if(s[i] == s[j]) {
					vis[i] = true;
					ans.push_back(make_pair(j, i));
					swap(t[i], s[j]);
					break;
				}
				if(s[i] == t[j]) {
					vis[i] = true;
					ans.push_back(make_pair(j, j));
					swap(s[j], t[j]);
					ans.push_back(make_pair(j, i));
					swap(s[j], t[i]);
					break;
				}
			}
		}
		len = ans.size();
		printf("Yes\n");
		printf("%d\n", len);
		for(int i = 0; i < len; ++i) {
			printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
		}
	}

    return 0;
}