#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr,arr+n);

		int ans=0,count=0,maxx=INT_MAX;
		for(int i=n-1;i>=0;i--){
			count++;
			maxx=min(arr[i],maxx);
			ans = max(ans,min(count,maxx));
		}

		cout<<ans<<endl;
	}
}