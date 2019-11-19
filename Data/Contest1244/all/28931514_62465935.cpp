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
	for (int i = 0; i < tests; i++) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int need_a = (a / c) + (int)(a % c != 0);
		int need_b = (b / d) + (int)(b % d != 0);
		if (need_a + need_b > k) {
			cout << -1 << "\n";
		}
		else {
			cout << need_a << " " << need_b << "\n";
		}
	}



	rt 0;
}