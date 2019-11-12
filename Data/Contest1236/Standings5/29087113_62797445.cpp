#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n;
vector<int> ans[310];

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	bool in = 1;
	for(int i = 1; i < n * n; i += n){
		int curr;
		if(in)	curr = 0;
		else 	curr = n - 1;
		for(int j = i; j < i + n; j++){
			ans[curr].push_back(j);
			if(in)	curr++;
			else 	curr--;
		}
		if(in)	in = 0;
		else	in = 1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
