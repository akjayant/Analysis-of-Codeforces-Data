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
#include <chrono>
#include<unordered_map>
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

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

unordered_map<long long, int, custom_hash> safe_map;

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

int nwd(int a, int b) { return b ? nwd(b, a%b) : a; }

int main()
{
	int t;
	scanf("%d", &t);
	REP(c, t)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		if (nwd(a, b) != 1)
			printf("Infinite\n");
		else
			printf("Finite\n");
	}

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
