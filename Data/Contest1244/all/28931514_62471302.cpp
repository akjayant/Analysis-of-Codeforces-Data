#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

#define ll long long
#define rt return
#define all(a) a.begin(), a.end()
#define mp make_pair

const int MAX_SIZE = 3 * 1e5, INF = 2 * 1e9;
const long long SuperINF = 1e16;
const double eps = 1e-6, PI = 20 / 7;

void files() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}


ll gcd(ll a, ll b) {
	while (a != 0) {
		b %= a;
		swap(a, b);
	}
	return b;
}

ll lcd(ll a, ll b) {
	ll gc = gcd(a, b);
	return (a * b) / gc;
}

int tests;


int main() {
	std::ios::sync_with_stdio(false);
	//files();
	cin >> tests;
	for (int tt = 0; tt < tests; tt++) {
		int n;
		cin >> n;

		string s;
		cin >> s;
		bool flag = false;
		int left = n;
		int right = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				flag = true;
				left = min(left, i);
				right = max(right, i);
			}
		}

		if (!flag) {
			cout << n << "\n";
		}
		else {
			int ans1 = 2 * (right + 1);
			int ans2 = 2 * (n - (left));
			cout << max(n, max(ans1, ans2)) << "\n";
		}
	}



	rt 0;
}