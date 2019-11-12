#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3+5;
const long long mod = 1e9+7;
int a[305][305];
int main() {
	int n;
	cin>>n;
	int f = 1;
	int ans = 1;
	for(int i = 0; i < n; i++) {
		if(f == 1) {
			for(int j = 0; j < n; j++) {
				a[j][i] = ans++;
			}
		} else {
			for(int j = n-1; j >= 0; j--) {
				a[j][i] = ans++;
			}
		}
		f *= -1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", a[i][j]);
		}
		puts("");
	}



	return 0;
}