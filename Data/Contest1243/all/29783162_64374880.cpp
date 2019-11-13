#include <bits/stdc++.h>

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

int main(){
	optimizar_io;
	int k;
	cin >> k;
	for (int t = 0; t < k; t++){
		int n;
		cin >> n;
		int data[n];
		for (int i = 0; i < n; i++){
			cin >> data[i];
		}
		for (int c = n; c >= 1; c--){
			int f = 0;
			for (int i = 0; i < n; i++){
				if (data[i] >= c) f++;
			}
			if (f >= c){
				cout << c << endl;
				break;
			}
		}
	}
	return 0;
}
