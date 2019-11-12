#include <bits/stdc++.h>
using namespace std;

long long k ,n,ans,arr[1005];
int main(){
	cin>>k;
	while(k--){
		cin>>n;
		for(int i =1;i<=n;i++){
			cin>>arr[i];

		}
		ans = 0;

		sort(arr+1,arr+n+1);
		for(int i =1;i<=n;i++){
			ans = max(ans,min(arr[i],n-i+1));
		}
		cout<<ans<<endl;
	}
}