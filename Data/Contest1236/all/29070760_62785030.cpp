#include <bits/stdc++.h>

using namespace std;

void runTestCase() {
	int a, b, c;
	cin >> a >> b >> c;

	int btake = (min(2*b, c)/2) * 3;
	b -= btake/3;

	int atake = (min(2*a, b)/2) * 3;

	cout << btake + atake << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for(int i =0; i < t; i++) {
		runTestCase();
	}

	return 0;
}
