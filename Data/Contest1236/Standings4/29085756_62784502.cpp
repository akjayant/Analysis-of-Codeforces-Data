#include<iostream>
using namespace std;

int main(){
	int t, a, b, c, count;
	cin >> t;
	for(int i = 1; i <= t; i++){
		count = 0;
		cin >> a >> b >> c;
		while(b > 0 and c > 1){
			b = b - 1;
			c = c - 2;
			count = count + 3;;
		}
		while(b > 1 and a > 0){
			a = a - 1;
			b = b - 2;
			count = count + 3;
		}
		cout << count << endl;
	}
}