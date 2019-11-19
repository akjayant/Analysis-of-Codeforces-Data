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










int main() {
#ifdef LOCAL
	fileopen();
#endif
	int T;
	cin >> T;
	while (T--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int cnt = 0;
		int u= a / c + (a%c != 0);
		int v= b / d + (b%d != 0);
		if (u + v <= k)cout << u << " " << v << endl;
		else cout << -1 << endl;
	}



#ifdef LOCAL
	fileclose();
#endif
	return 0;
}


