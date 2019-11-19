#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, SUM[510] = {}, MAX = -1, MAXL = 0, MAXR = 0;
	string S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') SUM[i + 1] = SUM[i] + 1;
		else SUM[i + 1] = SUM[i] - 1;
	}
	if (SUM[N] != 0) {
		cout << 0 << endl << 1 << " " << 1 << endl;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			string T = S;
			swap(T[i], T[j]);
			long long MIN = 0, COUNT = 0;
			for (int k = 0; k <= N; k++) SUM[k] = 0;
			for (int k = 0; k < N; k++) {
				if (T[k] == '(') SUM[k + 1] = SUM[k] + 1;
				else SUM[k + 1] = SUM[k] - 1;
				MIN = min(MIN, SUM[k + 1]);
			}
			for (int k = 0; k < N; k++) if (SUM[k] == MIN) COUNT++;
			if (MAX < COUNT) {
				MAX = COUNT;
				MAXL = i, MAXR = j;
			}
		}
	}
	cout << MAX << endl << MAXL + 1 << " " << MAXR + 1 << endl;
}