/*#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("Ofast")*/

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
//#include <random>
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
const long long mod_1 = 1000000007;
const long long mod_2 = 998244353;

vector<vector<int>> marks(6, vector<int>(3));
vector<vector<int>> g;

long long ANS = mx64;
vector<int> ans;

int START_V;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(25);

	marks[0][0] = 1; marks[0][1] = 2; marks[0][2] = 3;
	marks[1][0] = 1; marks[1][1] = 3; marks[1][2] = 2;
	marks[2][0] = 2; marks[2][1] = 1; marks[2][2] = 3;
	marks[3][0] = 2; marks[3][1] = 3; marks[3][2] = 1;
	marks[4][0] = 3; marks[4][1] = 1; marks[4][2] = 2;
	marks[5][0] = 3; marks[5][1] = 2; marks[5][2] = 1;

	int n; cin >> n; ans.resize(n + 1);
	vector<vector<long long>> cs(4, vector<long long>(n+1));
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cs[i][j];
		}
	}
	g.assign(n+1, vector<int>());

	for (int i = 0; i < n-1; i++) {
		int v, w; cin >> v >> w;
		g[v].push_back(w);
		g[w].push_back(v);
	}

	for (int i = 1; i <= n; i++) {
		if (g[i].size() == 1) {
			START_V = i;
			break;
		}
	}

	for (int H = 0; H < 6; H++)
	{
		int C = 1;

		long long NOW_ANS = 0;
		queue<int> bfs;
		vector<bool> vst(n+1, false);
		vector<int> now_color(n + 1);
		vst[START_V] = true;
		bfs.push(START_V); now_color[START_V] = marks[H][0];
		while (bfs.size()) {
			int now_v = bfs.front();
			bfs.pop();
			for (int i = 0; i < g[now_v].size(); i++) {
				int to = g[now_v][i];
				if (!vst[to]) {
					bfs.push(to);
					vst[to] = true;
					now_color[to] = marks[H][C % 3]; C++;
				}
			}
		}

		bool allow = true;
		for (int i = 1; i <= n; i++) {
			set<int> st; st.insert(now_color[i]);
			for (int j = 0; j < g[i].size(); j++) {
				int to = g[i][j];
				if (st.find(now_color[to]) == st.end()) {
					st.insert(now_color[to]);
				}
				else {
					allow = false;
					break;
				}
			}
		}

		if (allow) {
			for (int i = 1; i <= n; i++) {
				NOW_ANS += cs[now_color[i]][i];
			}
			if (NOW_ANS < ANS) {
				ANS = NOW_ANS;
				ans = now_color;
			}
		}
	}

	if (ANS != mx64) {
		cout << ANS << "\n";
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
	}
	else {
		cout << "-1";
	}

	//cout << "\n"; system("pause");
	return 0;
}
/*

*/