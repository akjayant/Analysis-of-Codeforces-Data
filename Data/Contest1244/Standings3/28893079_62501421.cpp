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

int main()
{
	int n;
	LL k;
	scanf("%d%lld", &n, &k);

	map<int, int> M;
	REP(i, n)
	{
		int a;
		scanf("%d", &a);
		M[a]++;
	}

	while (M.size() > 1 && k)
	{
		auto it1 = M.begin();
		auto rit1 = M.rbegin();

		// wybierz to, czego jest mniej
		if (it1->second <= rit1->second)
		{
			PII v = *it1;
			M.erase(it1);

			if ((M.begin()->first - v.first)*(LL)v.second > k)
			{
				v.first += k / v.second;
				k = 0;
				M.insert(v);
			}
			else
			{
				k -= (M.begin()->first - v.first)*(LL)v.second;
				M.begin()->second += v.second;
			}
		}
		else
		{
			PII v = *rit1;
			M.erase(v.first);

			if ((v.first - M.rbegin()->first)*(LL)v.second > k)
			{
				v.first -= k / v.second;
				k = 0;
				M.insert(v);
			}
			else
			{
				k -= (v.first - M.rbegin()->first)*(LL)v.second;
				M.rbegin()->second += v.second;
			}
		}
	}

	printf("%d\n", M.rbegin()->first - M.begin()->first);

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