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

const int MR = 2010;

pair<PII,PII> t[MR];

PII edges[MR*MR];

int p[MR], r[MR];

void makeset(int x)
{
	p[x] = x;
	r[x] = t[x].first.first;
}
void unionset(int x, int y)
{
	if (r[x] < r[y])
		p[y] = x;
	else
		p[x] = y;
}//union set
int findset(int x)
{
	if (p[x] != x)
		p[x] = findset(p[x]);
	return p[x];
}//find set

LL getCost(PII p)
{
	return (t[p.first].first.second + t[p.second].first.second)*(LL)(abs(t[p.first].second.first - t[p.second].second.first) + abs(t[p.first].second.second - t[p.second].second.second));
}
bool cmp(PII p1, PII p2)
{
	LL c1 = getCost(p1), c2 = getCost(p2);
	if (c1 != c2)
		return c1 < c2;
	return p1 < p2;
}

int main()
{
	int n;
	scanf("%d", &n);
	REP(i, n)
		scanf("%d%d", &t[i].second.first, &t[i].second.second);

	REP(i, n)
		scanf("%d", &t[i].first.first);
	REP(i, n)
		scanf("%d", &t[i].first.second);

	LL res = 0;
	set<int> V;
	vector<PII> E;

	REP(i, n)
	{
		res += t[i].first.first;
		V.insert(i);
		makeset(i);
	}

	int m = 0;
	REP(i, n)FOR(j, i + 1, n)
		edges[m++] = MP(i, j);
	sort(edges, edges + m, cmp);

	REP(i, m)
		if (findset(edges[i].first) != findset(edges[i].second))
		{
			LL c = getCost(edges[i]);
			int r1 = findset(edges[i].first), r2 = findset(edges[i].second);

			if (r[r1] > r[r2])
				swap(r1, r2);

			if (r[r2] > c)
			{
				res -= r[r2];
				V.erase(r2);

				res += c;
				E.push_back(edges[i]);

				unionset(r1, r2);
			}
		}

	printf("%lld\n", res);
	printf("%d\n", V.size());
	for (int v : V)
		printf("%d ", v + 1); printf("\n");
	printf("%d\n", E.size());
	for (auto e : E)
		printf("%d %d\n", e.first + 1, e.second + 1);

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