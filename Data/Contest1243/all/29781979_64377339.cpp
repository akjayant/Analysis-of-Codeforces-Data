//In the name of God
#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, res, a[N], t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> t;
	while(t --){
		cin >> n;	res = 0;
		fill_n(a, N, 0);
		for(int i = 0; i < n; i ++)
			cin >> a[i];
		sort(a, a + n, [](int i, int j){	return i > j; });
		for(int i = 0; i <= n; i ++)
			if(a[i] < i + 1){
				cout << i << "\n";
				break;	
			}
	}
	return 0;
}
