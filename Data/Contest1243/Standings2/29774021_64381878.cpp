#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

vi getDiv(int n){
	if(n == 1)
		return {1};
	vector<int> v;
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			v.PB(i);
			if(n / i != i)
				v.PB(n/i);
		}
	}
	return v;
}


int32_t main(){
	int n;
	cin >> n;
	vector<int> v = getDiv(n);
	if(v.size() == 0){
		cout << n;
		return 0;
	}
	int ans = v[0];
	for(int i = 1; i < (int)v.size(); i++){
		ans = __gcd(ans,v[i]);
	}
	cout << ans << endl;

	return 0;
}

