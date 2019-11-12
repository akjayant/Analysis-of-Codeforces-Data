#include <bits/stdc++.h>

#define LL long long

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	vector<vector<LL>> res(n,vector<LL>(n));
	LL curr = 1;
	for (LL i = 0; i < n; i += 2){
		for (LL j = 0; j < n; j++){
			res[j][i] = curr;
			curr++;
		}
		if (i == n-1)
			break;
		for (LL j = n-1; j >= 0; j--){
			res[j][i+1] = curr;
			curr++;
		}
	}
	for (LL i = 0; i < n; i++){
		cout << res[i][0];
		for (LL j = 1; j < n; j++)
			cout << " " << res[i][j];
		cout << "\n";
	}
}
