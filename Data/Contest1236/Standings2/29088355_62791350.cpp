#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N = 5*100000+1;
const int MOD = 1000000007;
const ll MAX = 10000000000;
const int oo = 1e9;

int n;

vector<int> g[310];

int main(){
	cin >> n;
	int cnt = 1;
	bool turn = true;
	for (int i = 0; i < n; ++i){
		if(turn){
			for(int j = 0 ; j < n ; ++j){
				g[j].push_back(cnt);
				cnt++;				
			}
		}else{
			for(int j = n-1 ; j >= 0 ; --j){
				g[j].push_back(cnt);
				cnt++;
			}
		}
		turn = !turn;
	}
	for (int i = 0; i < n; ++i){
		for(int j = 0 ; j < n ; ++j){
			if(j > 0)printf(" ");
			printf("%d",g[i][j]);
		}
		puts("");
	}
	return 0;
}