#include <bits/stdc++.h>
using namespace std;
#define asp " " 
#define aps ''
#define one 1
#define two 2
#define dif !=
typedef long long ll;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--){

		int a,b;
		cin >> a >> b;
		//if(a>b) swap(a,b);

		if(__gcd(a,b) dif one){
			cout << "Infinite" << endl; 
		}
		else cout << "Finite" << endl;
	}
}