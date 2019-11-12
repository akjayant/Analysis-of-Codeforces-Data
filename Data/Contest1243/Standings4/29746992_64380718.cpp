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












const int maxn = 1e4 + 5;

int n;
char s[maxn], t[maxn];
vector<int>d;

int main() {
#ifdef LOCAL
	fileopen();
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s%s", s + 1, t + 1);
		for (int i = 1; i <= n; i++) {
			if (s[i] != t[i])d.push_back(i);
		}
		if (d.size() != 2) printf("No\n");
		else {
			int a = d[0], b = d[1];
			if (s[a] == s[b] && t[a] == t[b])printf("Yes\n");
			else printf("No\n");
		}
		d.clear();
	}

#ifdef LOCAL
	fileclose();
#endif
	return 0;
}