#include <bits/stdc++.h>

using namespace std;

void test_case(){
	int n; cin >> n;
	vector <int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end(),greater<int>());
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,min(i+1,a[i]));
	}
	cout << ans << endl;
	return;
}

int main(){
	int t; cin >> t;
	while(t--){
		test_case();
	}
	return 0;
}