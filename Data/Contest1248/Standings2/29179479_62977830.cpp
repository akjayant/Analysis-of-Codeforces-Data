#include <iostream>

using namespace std;

typedef long long ll;
#define x first
#define y second
#define mp make_pair

ll br[2][2];
int n, m;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int temp;
cin >> temp;
while(temp--){
	cin >> n;
	for(int i = 0 ; i < 2 ; ++i){
		for(int j = 0 ; j < 2 ; ++j){
			br[i][j] = 0;
		}
	}
	for(int i = 0 ; i < n ; ++i){
		int x;
		cin >> x;
		br[0][x & 1]++;
	}
	cin >> m;
	for(int i = 0 ; i < m ; ++i){
		int x;
		cin >> x;
		br[1][x & 1]++;
	}
	ll sol = br[0][0] * br[1][0] + br[0][1] * br[1][1];
	cout << sol << endl;
}

return 0;
}

