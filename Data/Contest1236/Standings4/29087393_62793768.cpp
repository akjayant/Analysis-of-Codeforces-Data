// youngjinp20
// 2019 10

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;

int A[301][301];

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			A[j][i] = i*n + (i&1 ? n-j: j+1);
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			printf("%d ", A[i][j]);
		}
		puts("");
	}

	return 0;
}
