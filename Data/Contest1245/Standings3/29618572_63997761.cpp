#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;


int main() {
	int64_t a, b, t, q, w, rr;
	cin >> t;
	for (int ii = 0; ii < t; ++ii) {
		cin >> a >> b;
		if (a > b) {
			q = a;
			w = b;
		} else {
			q = b;
			w = a;
		}
		while (w > 0) {
			rr = q % w;
			q = w;
			w = rr;
		}
		if (q > 1) {
			cout << "Infinite\n";
		} else {
			cout << "Finite\n";
		}
	}

}