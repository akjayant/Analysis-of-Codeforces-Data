#include<iostream>
using namespace std;

int main(){
	int a[301][301], n;
	cin >> n;
	int t = n * n;
	for(int i = 1; i <= n; i++){
		if(i % 2 == 1){
			for(int j = 1; j <= n; j++){
				a[j][i] = t;
				t--;
			}
		}
		if(i % 2 == 0){
			for(int j = n; j >= 1; j--){
				a[j][i] = t;
				t--;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}