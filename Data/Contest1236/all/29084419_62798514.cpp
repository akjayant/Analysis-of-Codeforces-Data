/* 	* Author: ReSi
 	* Time: 2019-10-17 17:27:33
**/

#include <bits/stdc++.h>

using namespace std;

#define mP make_pair
#define ll long long
#define pB push_back
#define X first
#define Y second

int main(){
	int n;
	cin >> n;

	vector<int> table[n + 10];

	bool dir = 0;
	int cnt = 1;
	for(int j = 0; j < n; ++j){
		if(dir == 0){
			for(int i = 0; i < n; ++i){
				table[i].push_back(cnt);
				++cnt;
			}	
		}else{
			for(int i = n - 1; i >= 0; --i){
				table[i].push_back(cnt);
				++cnt;
			}
		}
		dir = 1 - dir;
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	

	return 0;
}
