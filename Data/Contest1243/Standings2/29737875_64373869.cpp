# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int) 1e5 + 1;

int t;
int n;
int a[maxn];
int main(){
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);
		int ok = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] < i){
				cout << i - 1 << "\n";
				ok = 1;
				break;
			}
		}
		if(!ok){
			cout << n << "\n";
		}
	}
	return 0;
}