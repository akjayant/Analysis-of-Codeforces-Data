//In the name of God
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e3 + 10;



int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int n;	cin >> n;
	for(int i = 2; i * i <= n; i ++)
		if(n % i == 0){
			while(n % i == 0)	n /= i;
			if(n > 1)	return cout << 1, 0;
			return cout << i, 0;
		}
	cout << n;
	return 0;
}
