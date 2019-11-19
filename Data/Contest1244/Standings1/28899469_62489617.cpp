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



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(20);
	srand((unsigned int)TMP);
	LL N, K; cin >> N >> K;
	string S; cin >> S;
	S = S + S + S;
	VLL fix(3*N);
	if (S.at(0) == S.at(1)) { fix.at(0) = 1; }
	if (S.at(3*N - 2) == S.at(3*N - 1)) { fix.at(3*N - 1) = 1; }
	FU(i, 1, 3*N-1) {
		if (S.at(i) == S.at(i - 1) || S.at(i) == S.at(i + 1)) {
			fix.at(i) = 1;
		}
	}
	S = S + S + S;
	LL lf = -1;
	VLL clfix(3*N, LLONG_MAX);
	FU(i, 0, 2 * N) {
		if (fix.at(i)) {
			lf = i;
		}
		if (lf != -1) {
			clfix.at(i) = lf;
		}
	}
	lf = -1;
	FD(i, 3*N - 1, -1) {
		if (fix.at(i)) {
			lf = i;
		}
		if (lf != -1) {
			if (abs(lf - i) < abs(i - clfix.at(i))) {
				clfix.at(i) = lf;
			}
		}
	}
	string res;
	FU(i, N, 2*N) {
		if (abs(clfix.at(i)-i) > K) {
			if (K % 2 == 0) {
				res.PB(S.at(i));
			}
			else {
				res.PB((char)((LL)'W' + (LL)'B' - S.at(i)));
			}
		}
		else {
			res.PB(S.at(clfix.at(i)));
		}
	}
	cout << res;
	return 0;
}