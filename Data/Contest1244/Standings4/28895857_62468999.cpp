#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(){
	int t, n;
	cin >> t;
	string s;
	for (int i = 0; i < t; i++){
		cin >> n >> s;
		int a1 = -1, a2 = -1;
		for (int j = 0; j < n; j++){
			if (s[j] == '1'){
				a1 = (n - j) * 2;
				break;
			}
		}
		for (int j = n - 1; j >= 0; j--){
			if (s[j] == '1'){
				a2 = (j + 1) * 2;
				break;
			}
		}
		if (a1 == -1){
			printf("%d\n", n);
		}else if (a1 > a2){
			printf("%d\n", a1);
		}else{
			printf("%d\n", a2);
		}
	}
}