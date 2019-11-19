# include <bits/stdc++.h>
# define ll long long
using namespace std;
int main(){
	ll n;
	cin >> n;
	if(n == 1){
		cout << "1"; return 0;
	}
	vector < ll > dv; 
	for(ll i = 2; i * i <= n; i ++){
		bool ok = false;
		while(n % i == 0){
			ok = true;
			n /= i;
		}
		if(ok) dv.push_back(i);
	}
	if(n != 1)dv.push_back(n);
	if(dv.size() > 1){
		cout << "1"; return 0;
	}
	cout << dv[0] << "\n";
}