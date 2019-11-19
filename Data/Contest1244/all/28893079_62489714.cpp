#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define ALL(u) (u).begin(),(u).end()

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

typedef pair<int, int> PII;

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

const int MR = 1e5 + 10;

const LL inf = 1e18;

LL dp[MR][3][3];

int cost[MR][3];

vector<int> g[MR];

bool done[MR];

int res[MR];

void dfs(int nr)
{
	int par = -1;
	done[nr] = 1;
	for (int v : g[nr])
		if (!done[v])
			dfs(v);
		else
			par = v;

	REP(col1, 3)REP(col2, 3)
	{
		if (col1 == col2)
		{
			dp[nr][col1][col2] = inf;
			continue;
		}

		dp[nr][col1][col2] = cost[nr][col1];

		for (int v : g[nr])
			if (v != par)
			{
				LL add = inf;
				REP(col3, 3)
					if (col3 != col1 && col3 != col2)
						add = min(add, dp[v][col2][col3]);

				if (add == inf)
				{
					dp[nr][col1][col2] = inf;
					break;
				}

				dp[nr][col1][col2] += add;

			}
	}
}

void go(int nr, int col1, int col2)
{
	done[nr] = 0;

	REP(i, 3)
		if (i != col1 && i != col2)
			res[nr] = i;

	for (int v : g[nr])
		if (done[v])
			go(v, res[nr], col1);
}

int main()
{
	int n;
	scanf("%d", &n);

	REP(j, 3)REP(i, n)
		scanf("%d", &cost[i][j]);

	REP(i, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v); u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int root = 0;
	REP(i, n)
		if (g[i].size() > 2)
		{
			printf("-1\n");
			return 0;
		}
		else if (g[i].size() == 1)
			root = i;

	dfs(root);

	LL sum = inf;
	int bad1 = -1, bad2 = -1;
	REP(col1, 3)REP(col2, 3)
		if (dp[root][col1][col2] < sum)
		{
			sum = dp[root][col1][col2];

			REP(col3, 3)
				if (col3 != col1 && col3 != col2)
				{
					bad1 = col3;
					bad2 = col2;
					break;
				}
		}

	if (sum == inf)
	{
		printf("-1\n");
		return 0;
	}

	printf("%lld\n", sum);

	go(root, bad1, bad2);

	REP(i, n)
		printf("%d ", res[i] + 1);
	printf("\n");

	return 0;
}

// FOR GNU C++ use the following pattern:
// Uncomment the code below and change your main into main2
// It does not build in MS C++
// But it does increase the stack size from 256 MB on CF and uses GNU C++

//#include <Processthreadsapi.h>
//#include <iostream>
//#include <Synchapi.h>
//#include <windows.h>
//#include <process.h>
//
//DWORD WINAPI MyThreadFunction(LPVOID lpParam) {
//    main2(nullptr);
//    return 0;
//}
//int main() {
//    auto h = CreateThread(nullptr, 1024 << 20, MyThreadFunction, nullptr, STACK_SIZE_PARAM_IS_A_RESERVATION, nullptr);
//    WaitForSingleObject(h, INFINITE);
//}