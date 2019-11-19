#include "bits/stdc++.h"
using namespace std;

int main() {
	long long T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		long long N, M, P, P2[2] = {}, Q, Q2[2] = {};
		cin >> N;
		for (int i = 0; i < N; i++) cin >> P, P2[P % 2]++;
		cin >> M;
		for (int i = 0; i < M; i++) cin >> Q, Q2[Q % 2]++;
		cout << P2[0] * Q2[0] + P2[1] * Q2[1] << endl;
	}
}