#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		sort(a+1,a+n+1);
		int cnt = 0;
		int wyn = -1;
		for (int i = n; i >= 1; --i){
			if (a[i] > wyn){
				cnt++;
				wyn = max(wyn, min(a[i],cnt));
			}
		}
		cout << wyn << "\n";
	}

}