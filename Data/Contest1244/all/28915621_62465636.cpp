#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	iostream::sync_with_stdio(0);
	int t;
	cin>>t;
	for (; t; t--) {
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int res = a / c + (a % c >= 1) + b / d + (b % d >= 1);
		if (res > k) cout<<-1<<endl; else cout<<(a / c + (a % c >= 1))<<" "<<(b / d + (b % d >= 1))<<endl;
	}
}