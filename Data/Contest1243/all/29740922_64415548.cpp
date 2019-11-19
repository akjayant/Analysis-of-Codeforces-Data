#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("Ofast")

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
#include <random>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <map>
#include <set>

using namespace std;

const long double PI = 3.14159265358979323846264338328;
const long long mx64 = 9223372036854775807;
const int mx32 = 2147483647;
const short int mx16 = 32767;
const long long mod1 = 1000000007;
const long long mod2 = 998244353;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(25);

	int n, m;
	cin >> n >> m;
	vector<set<int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		g[u].insert(v);
		g[v].insert(u);
	}
	set<int> outg;
	for (int i = 0; i < n; i++) {
		g[i].insert(n);
		outg.insert(i);
		if (!g[i].size()) {
			cout << 0;
			return 0;
		}
	}

	int cnt = 0;
	vector<bool> ing(n, false);
	for (int i = 0; i < n; i++) {
		if (!ing[i]) {
			cnt++; ing[i] = true;
			queue<int> bfs;
			bfs.push(i);
			outg.erase(i);
			while (bfs.size() && outg.size())
			{
				int v = bfs.front();
				bfs.pop();
				set<int>::iterator tr = outg.begin();
				vector<int> need_delete;
				for (int gg : g[v]) {
					while (tr != outg.end() && *tr < gg) {
						int TR = *tr;
						need_delete.push_back(TR);
						if (!ing[TR]) {
							bfs.push(TR);
							ing[TR] = true;
						}
						tr++;
					}
					if (tr == outg.end()) {
						break;
					}
					tr = outg.upper_bound(gg);
				}
				for (int delet : need_delete) {
					outg.erase(delet);
				}
			}
		}
	}

	cout << cnt - 1;
	//cout << "\n"; system("pause");
	return 0;
}
/*

*/