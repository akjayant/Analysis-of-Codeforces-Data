#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, A[100000], R = 0, U = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	for (int i = 0; i < N / 2; i++) R += A[i];
	for (int i = N / 2; i < N; i++) U += A[i];
	cout << R * R + U * U;
}