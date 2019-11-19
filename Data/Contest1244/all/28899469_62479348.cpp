#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include <time.h>
#include<chrono>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define UI unsigned int
#define LL long long
#define GT(it,v) for(auto it:v)
#define FU(i,a,b) for(LL i=(a);i<(b);i++)
#define FD(i,a,b) for(LL i=(a);i>(b);i--)
#define LD long double
#define PI 3.1415926535897932384626
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VLL vector<long long >
#define VVLL vector<vector<long long > >
#define VVVLL vector<vector<long long > >
#define VPLL vector<pair<long long, long long>>
#define VVPLL vector<vector<pair<long long, long long>>>
#define VD vector<double>
#define VVD vector<vector<double> >
#define VPD vector<pair<double,double> >
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define SORT(v) sort(v.begin(),v.end())
#define GSORT(v,what) sort(v.begin(),v.end(),greater<what>())
using namespace std; LL inp; LL i1, i2, i3, i4, i5, i6, i7, i8;
LL MOD = 998244353, MOD1 = (LL)1e9 + 7, MOD2 = (LL)1e9 + 9; long long MOD3 = (long long)1e9 + 21 /*33*/;  double eps = 1e-9;
LL TMP = (chrono::high_resolution_clock::now().time_since_epoch().count() % MOD + MOD) % MOD;
auto STTMP = chrono::steady_clock::now();//auto ENTMP = chrono::steady_clock::now();
//ELTIME = double(chrono::duration_cast<chrono::milliseconds>(ENTMP - STTMP).count());

VVLL G;
VVLL c123(3);
VLL vis;

LL dfs(LL pos, LL col, LL inc) {
	LL cost = c123.at(col).at(pos);
	GT(next, G.at(pos)) {
		if (!vis.at(next)) {
			vis.at(next) = (col + inc + 3) % 3 +1;
			cost += dfs(next, (col + inc + 3) % 3, inc);
		}
	}
	return cost;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(20);
	srand((unsigned int)TMP);
	LL N; cin >> N;
	G.resize(N);
	FU(i, 0, N) {
		cin >> inp; c123.at(0).PB(inp);
	}
	FU(i, 0, N) {
		cin >> inp; c123.at(1).PB(inp);
	}
	FU(i, 0, N) {
		cin >> inp; c123.at(2).PB(inp);
	}
	FU(i, 0, N - 1) {
		cin >> i1 >> i2; i1--, i2--;
		G.at(i1).PB(i2); G.at(i2).PB(i1);
	}
	LL startn = 0;
	FU(i, 0, N) {
		if (G.at(i).size() > 2) {
			cout << -1;
			return 0;
		}
		else if (G.at(i).size() == 1) {
			startn = i;
		}
	}
	
	LL res = LLONG_MAX;
	VLL rec;
	vis.clear(), vis.resize(N); vis.at(startn) = 1;
	LL tmp = dfs(startn, 0, 1);
	if (tmp < res) {
		res = tmp;
		rec = vis;
	}
	vis.clear(), vis.resize(N); vis.at(startn) = 2;
	tmp = dfs(startn, 1, 1);
	if (tmp < res) {
		res = tmp;
		rec = vis;
	}
	vis.clear(), vis.resize(N); vis.at(startn) = 3;
	tmp = dfs(startn, 2, 1);
	if (tmp < res) {
		res = tmp;
		rec = vis;
	}
	vis.clear(), vis.resize(N); vis.at(startn) = 1;
	tmp = dfs(startn, 0, -1);
	if (tmp < res) {
		res = tmp;
		rec = vis;
	}
	vis.clear(), vis.resize(N); vis.at(startn) = 2;
	tmp = dfs(startn, 1, -1);
	if (tmp < res) {
		res = tmp;
		rec = vis;
	}
	vis.clear(), vis.resize(N); vis.at(startn) = 3;
	tmp = dfs(startn, 2, -1);
	if (tmp < res) {
		res = tmp;
		rec = vis;
	}
	cout << res << "\n";
	GT(it, rec) {
		cout << it << " ";
	}

	return 0;
}