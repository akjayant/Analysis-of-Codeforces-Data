#include <bits/stdc++.h>

using namespace std;



void prepare() {
	
}

void read() {
	
}

void solve() {
	int n;	
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}	
	sort(a.rbegin(), a.rend());
	int answer = 1;
	for (int i = 0; i < n; i++) {
		int can = min(i + 1, a[i]);
		answer = max(answer, can);
	}
	printf("%d\n", answer);
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	
	prepare();
	read();
	int test;
	scanf("%d", &test);
	for (int t = 0; t < test; t++) {
		solve();
	}
	
	return 0;
}



