# include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin >> q;
	while(q --){
		int n , res = 0;
		cin >> n;
		int a[n + 1];
		for(int i = 1; i <= n; i ++) cin >> a[i];
		sort(a + 1 , a + n + 1);
		for(int i = n; i >= 1; i --){
			res = max(res , min(a[i] , n - i + 1));
		}
		cout << res << '\n';
	}
}