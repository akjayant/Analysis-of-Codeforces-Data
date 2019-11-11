
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>
#include <sstream>
#include <map>
#include <math.h>
#include <stdio.h>
#include <stack>
#include <set>

using  namespace std;
#define ll long long
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else return (gcd(b, a % b));
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		if (gcd(a, b) == 1) cout << "Finite" << '\n';
		else cout << "Infinite" << endl;
	}
}