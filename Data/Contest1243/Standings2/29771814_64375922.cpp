#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int a[N];
int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		int ct = 0, ans;
		for(int i = n - 1; i >= 0; i--){
			if(a[i] >= ct + 1) ct = ct + 1;
			
		}
		cout << ct << "\n";
	}
	
	return 0;
}
