#include <bits/stdc++.h>
using namespace std;

const int L = 310;
int tab[L][L];
int N;

int val(){

	int ans = N*N;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(i == j) continue;

			int cnt = 0;

			for(int k=0; k<N; k++){
				for(int l=0; l<N; l++){
					if(tab[i][k] > tab[j][l]) cnt++;
				}
			}

			cout << i << " with " << j << ": " << cnt << '\n';

			ans = min(ans, cnt);
		}
	}

	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	int l = 1, r = N*N;

	if(N%2 == 0){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(j<(N>>1)) tab[i][j] = l++;
				else tab[i][j] = r--;
			}
		}
	}
	else{
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(j<(N>>1)) tab[i][j] = l++;
				else tab[i][j] = r--;
			}
		}

		for(int i=0; i<(N>>1); i++){
			swap(tab[i][N>>1], tab[N-1-i][N>>1]);
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << tab[i][j] << ' ';
		}
		cout << '\n';
	}

	//cout << val() << '\n';

	return 0;
}