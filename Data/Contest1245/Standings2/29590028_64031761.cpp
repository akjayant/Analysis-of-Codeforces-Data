//besmellah
#include <bits/stdc++.h>
using namespace std;

#define int long long

int h[100], p[100];
long double E[150], G[150];

int P(int a, int b){
	if (!b)
		return a;
	return p[P(a, b - 1)];
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 9; i >= 0; i --){
		if (i % 2){
			for (int j = 9; j >= 0; j --){
				cin >> h[i * 10 + j];
				p[i * 10 + j] = i * 10 + j + 2 * (9 - j) + 1;
			}
		}
		else{
			for (int j = 0; j < 10; j ++){
				cin >> h[i * 10 + j];
				p[i * 10 + j] = i * 10 + j + 2 * (9 - j) + 1;
			}
		}
	}
	E[99] = 0;
	G[99] = 0;
	E[98] = 6;
	G[98] = 6;
	E[97] = 6;
	G[97] = 6;
	E[96] = 6;
	G[96] = 6;
	E[95] = 6;
	G[95] = 6;
	E[94] = 6;
	G[94] = 6;
	for (int i = 93; i >= 0; i --){
		long double R = 0;
		for (int j = 1; j <= 6; j ++){
			R += E[i + j];
		}
		E[i] = 1.00 + 1.00 / 6.00 * R;
		G[i] = E[i];
		int q = P(i, h[i]);
		E[i] = min(E[i], G[q]);
	}
	cout << setprecision(18) << fixed << E[0];
}
