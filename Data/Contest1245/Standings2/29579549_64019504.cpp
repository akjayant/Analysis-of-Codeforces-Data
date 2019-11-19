/*
Московченко Иван Дмитриевич
Лабораторная работа №7
*/

#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:32100000")
#pragma GCC optimize("O3")

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <cstring>
#include <cassert>
#include <fstream>
#include <map>
#include <unordered_map>
#include <deque>
#include <unordered_set>

using namespace std;

#define inf 1000000007
#define eps 1e-9
#define mp(a, b) make_pair(a, b)
#define llinf 1000000000000000007LL

typedef long long ll;
typedef unsigned u;
typedef long double ld;
typedef unsigned char uc;
typedef unsigned long long ull;

int n;
pair <int, int> coord[2048];
int c[2048];
int k[2048];
ll g[2048][2048];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cout.precision(9);
	srand(time(0));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> coord[i].first >> coord[i].second;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
	}
	
	for (int i = 1; i <= n; i++) {
		g[0][i] = g[i][0] = c[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = 1LL * (k[i] + k[j]) * (abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second));
		}
	}
	vector<bool> used(n + 1);
	vector<int> min_e(n + 1, inf), sel_e(n + 1, -1);
	min_e[0] = 0;


	ll ANS = 0LL;
	vector <int> ans1;
	vector <pair <int, int>> ans2;

	for (int i = 0; i <= n; i++) {
		int v = -1;
		for (int j = 0; j <= n; j++) {
			if (!used[j] && (v == -1 || min_e[j] < min_e[v])) {
				v = j;
			}
		}
		
		used[v] = 1;
		if (sel_e[v] != -1) {
			ANS += g[v][sel_e[v]];
			if (v == 0) {
				ans1.push_back(sel_e[v] + 1);
			}
			else if (sel_e[v] == 0) {
				ans1.push_back(v);
			}
			else {
				ans2.push_back({ v, sel_e[v]});
			}
		}
		for (int to = 0; to <= n; to++) {
			if (g[v][to] < min_e[to]) {
				min_e[to] = g[v][to];
				sel_e[to] = v;
			}
		}
	}
	cout << ANS << "\n" << ans1.size() << "\n";
	for (auto &i : ans1) {
		cout << i << " ";
	}
	cout << "\n" << ans2.size() << "\n";
	for (auto &i : ans2) {
		cout << i.first << " " << i.second << "\n";
	}
	return 0;
}