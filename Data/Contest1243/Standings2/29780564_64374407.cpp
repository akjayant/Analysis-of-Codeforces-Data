#include <bits/stdc++.h>

using namespace std;

int main(){
	int k;
	cin >> k;
	while(k--){
		int n;
		cin >> n;
		int v[n + 10];

		for(int i = 1;i <= n;i++)
			cin >> v[i];
		sort(v + 1, v + 1 + n);

		int ans = 0;
		for(int i = 1;i <= n;i++){
			if(i + v[i] <= n)
				ans = max(ans, v[i]);
			else if(n - i + 1 <= v[i])
				ans = max(ans, n - i + 1);
		}
		cout << ans << "\n";
	}
}