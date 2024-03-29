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
//#include <time.h>
#include<chrono>
#include <ctime>
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
#define GSORT(v,what) sort(v.begin(),v.end(),greater<what>)
#define UNIQUE(it,v) (it = unique(v.begin(),v.end()), v.resize(distance(v.begin(),it)))
using namespace std; LL inp, Inp; LL i1, i2, i3, i4, i5, i6, i7, i8;
LL MOD = 998244353, MOD1 = (LL)1e9 + 7, MOD2 = (LL)1e9 + 9; long long MOD3 = (long long)1e9 + 21 /*33*/;  double eps = 1e-9;
LL TMP = (chrono::high_resolution_clock::now().time_since_epoch().count() % MOD + MOD) % MOD;
auto STTMP = chrono::steady_clock::now();//auto ENTMP = chrono::steady_clock::now();
//ELTIME = double(chrono::duration_cast<chrono::milliseconds>(ENTMP - STTMP).count());
//time_t result = time(NULL); char SS[26]; ctime_s(SS, sizeof SS, &result);
//transform(SS, SS + 26, SS, [](char ch) {return ch == ' ' ? '_' : ch; }); printf("%s", SS);
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	LL T; cin >> T;
	FU(t, 0, T) {
		LL N; cin >> N;
		string S1, S2; cin >> S1 >> S2;
		vector<pair<char, char>> mm;
		FU(i, 0, N) {
			if (S1.at(i) != S2.at(i)) {
				mm.PB({ S1.at(i), S2.at(i) });
			}
		}
		if (mm.size() == 0) {
			cout << "Yes";
		}
		else if (mm.size() == 1) {
			cout << "No";
		}
		else if (mm.size() == 2) {
			if ((mm.at(0).first == mm.at(1).first && mm.at(0).second == mm.at(1).second)) {
				cout << "Yes";
			}
			else {
				cout << "No";
			}
		}
		else {
			cout << "No";
		}
		cout << "\n";
	}
}