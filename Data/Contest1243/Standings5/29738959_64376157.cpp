#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main(){
	sync
	int t;
	cin >> t;
	while(t--){
		int n,ans=1;
		cin >> n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++){
			ans=max(ans,min(a[i],n-i));
		}
		cout << ans << "\n";
	}
	return 0;
}