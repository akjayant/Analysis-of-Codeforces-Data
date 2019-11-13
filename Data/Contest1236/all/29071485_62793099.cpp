#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e2 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int N, A[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int cnt = N * N;
	for(int i=1; i<=N; i++) {
		if(i % 2) for(int j=1; j<=N; j++) A[j][i] = cnt--;
		else for(int j=N; j>=1; j--) A[j][i] = cnt--;
	}
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) cout << A[i][j] << ' ';
		cout << '\n';
	}
}