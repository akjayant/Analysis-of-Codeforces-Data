/* ashwani_er */

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	
	int a=0,b=0;
	for(int i=0;i<n/2;i++){
		a+=arr[i];
	}
	for(int i=n/2;i<n;i++){
		b+=arr[i];
	}
	cout<<(a*a + b*b)<<endl;
}
