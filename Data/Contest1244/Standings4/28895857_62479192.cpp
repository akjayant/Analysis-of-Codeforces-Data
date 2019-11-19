#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	long long int n;
	scanf("%lld", &n);
	long long int c[3][n], d[n];
	for (long long int i = 0; i < 3; i++){
		for (long long int j = 0; j < n; j++){
			scanf("%lld", &c[i][j]);
			d[j] = 0;
		}
	}
	vector<int> a[n];
	bool bad = false;
	for (long long int i = 0; i < n - 1; i++){
		long long int x, y;
		scanf("%lld %lld", &x, &y);
		x--;
		y--;
		d[x]++;
		d[y]++;
		if (d[x] > 2 || d[y] > 2){
			bad = true;
		}
		a[x].push_back(y);
		a[y].push_back(x);
	}
	if (bad){
		printf("-1\n");
		return 0;
	}
	long long int s;
	for (long long int i = 0; i < n; i++){
		if (d[i] == 1){
			s = i;
		}
	}
	long long int p[3] = {0, 1, 2}, ans = 999999999999999, pp[3];
	for (long long int i = 0; i < 6; i++){
		long long int cur = s, sum = 0, par = -1;
		for (long long int j = 0; j < n; j++){
			sum += c[p[j % 3]][cur];
			if (a[cur][0] != par){
				par = cur;
				cur = a[cur][0];
			}else{
				par = cur;
				cur = a[cur][1];
			}
		}
		if (ans > sum){
			ans = sum;
			for (long long int j = 0; j < 3; j++){
				pp[j] = p[j];
			}
		}
		next_permutation(p, p + 3);
	}
	printf("%lld\n", ans);
	long long int cur = s, par = -1, aaa[n];
	for (long long int j = 0; j < n; j++){
		aaa[cur] = pp[j % 3];
		if (a[cur][0] != par){
			par = cur;
			cur = a[cur][0];
		}else{
			par = cur;
			cur = a[cur][1];
		}
	}
	for (long long int i = 0; i < n; i++){
		printf("%lld ", aaa[i] + 1);
	}
}