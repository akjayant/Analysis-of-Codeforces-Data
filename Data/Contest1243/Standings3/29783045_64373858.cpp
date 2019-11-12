#include <bits/stdc++.h>
using namespace std;
long long t, n, a[1005];
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> t;
while (t--){
	cin >> n; for (int i=0; i<n; i++) cin >> a[i];
	sort (a, a+n); 
	for (int i=0; i<n; i++){
		if (a[i]>=n-i){
			cout << n-i << endl;
			break;
		}
	}
}
return 0;
}
