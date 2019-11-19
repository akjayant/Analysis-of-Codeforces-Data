#include <bits/stdc++.h>

using namespace std;

int main(){
	#define int long long
	int n;
	cin >> n;

	set<int> div;
	for(int i = 2;i * i <= n;i++)
		if(n % i == 0)
			div.insert(i), div.insert(n / i);
	// dbg(div);
	int mdc = 0;
	for(auto u : div)
		mdc = __gcd(mdc, u);
	cout << (mdc == 0 ? n : mdc) << "\n";
}