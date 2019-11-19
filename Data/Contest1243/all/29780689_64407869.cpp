#include<bits/stdC++.H>
using namespace std;
#define ll long long
ll n, k, a[200000];
#define pb push_back
int main(){
	cin >> k;
	string s, t;
	if (k == 1) {
	 	cout << 1;
	 	return 0;
	}
	if (!(k & (k - 1))) {
		cout << 2;
		return 0;
	}
	int x = 0;
	ll last = 0;

	for (ll i = 2; i * i <= k; i++)
		if (k % i == 0){ 
			 x++;
			while (k % i == 0)	
				k /= i;
			last = i;
		}
		
	if (k > 1) {
	 	last = k;
	 	x++;
	}
	if (x > 1) {
	 	cout << 1;
	} else cout << last;


}
