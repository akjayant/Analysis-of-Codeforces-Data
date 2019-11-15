#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<map>
#include<unordered_map>
#ifdef LOCAL
#include"file.h"
#endif

#define y1 zyy_orz
#define hash sto_zyy

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL>pLL;
typedef pair<int, int>pii;
const double eps = 1e-10;
const double Pi = 3.1415926535897932;
const int dir[4][2] = { -1,0,0,-1,1,0,0,1 };
//const int dir[8][2] = { -2,-1,-2,1,2,-1,2,1,-1,2,-1,-2,1,2,1,-2 };







char s[55], t[55];
int n;

vector<pii> ans;

int find(char *p, int i, char ch) {
	for (; i <= n; i++) {
		if (p[i] == ch)return i;
	}
	return -1;
}

int main() {
#ifdef LOCAL
	fileopen();
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s%s", s + 1, t + 1);
		bool ok = true;
		for (int i = 1; i <= n; i++)if(s[i]!=t[i]) {
			int p = find(s, i + 1, s[i]);
			if (p != -1) {
				swap(s[p], t[i]);
				ans.push_back(pii{ p,i });
			}
			else {
				p = find(t, i, s[i]);
				if(p==-1){
					ok = false;
					break;
				}
				swap(s[n], t[p]);
				swap(s[n], t[i]);
				ans.push_back(pii{ n,p });
				ans.push_back(pii{ n,i });
			}
		}
		if (!ok)printf("No\n");
		else {
			printf("Yes\n%d\n", ans.size());
			for (int i = 0; i < ans.size(); i++) {
				printf("%d %d\n", ans[i].first, ans[i].second);
			}
		}
		ans.clear();
		vector<pii>tt;
		swap(ans, tt);
	}
#ifdef LOCAL
	fileclose();
#endif
	return 0;
}


