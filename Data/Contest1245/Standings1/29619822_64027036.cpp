#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

#define repeat(n) for(register LL ______________ = (n); ______________ > 0; --______________)
#define loop(i, l, r) for(register LL i = (l), ________r = (r); i <= ________r; ++i)
#define iloop(i, l, r) for(register LL i = (l), ________r = (r); i < ________r; ++i)
#define rloop(i, r, l) for(register LL i = (r), ________l = (l); i >= ________l; --i)

typedef long long LL;

#ifdef CAI_WEI_HAN
#include "LOG.h"
#else
#define LOG(...) 1
#endif

signed main()
{
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
	#define cout cerr
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	constexpr char endl = '\n';
	
	int G[11][11];
	loop(i, 1, 10)
	loop(j, 1, 10)
		cin >> G[i][j];
	
	pair<int, int> Next[11][11];
	pair<int, int> inv_Next[11][11];
	loop(i, 1, 10) {
		if(i & 1) {
			loop(j, 2, 10) {
				Next[i][j] = { i, j-1 };
				inv_Next[i][j-1] = { i, j };
			}
			Next[i][1] = { i-1, 1 };
			inv_Next[i-1][1] = { i, 1 };
		}
		
		else {
			loop(j, 1, 9) {
				Next[i][j] = { i, j+1 };
				inv_Next[i][j+1] = { i, j };
			}
			Next[i][10] = { i-1, 10 };
			inv_Next[i-1][10] = { i, 10 };
		}
	}
	
	double F[11][11]{};
	F[1][1] = 0;
	F[1][2] = 6;
	F[1][3] = 6;
	F[1][4] = 6;
	F[1][5] = 6;
	F[1][6] = 6;
	int i = 1, j = 6;
	while(i != 10 || j != 1) {
		auto pa = inv_Next[i][j];
		i = pa.first;
		j = pa.second;
		
		int ii = i, jj = j;
		repeat(6) {
			auto pa = Next[ii][jj];
			ii = pa.first;
			jj = pa.second;
			
			F[i][j] += 1.0/6 * min(F[ii][jj], F[ii - G[ii][jj]][jj]);
		}
		F[i][j] += 1;
	}
	
	printf("%.10f", F[10][1]);
}