#include<bits/stdc++.h>
using namespace std;
#define N 2005
int n,a[N];

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		int ans=0;
		
		for(int i=n;i>=1;i--){
			ans=max(ans,min(a[i],n-i+1));	
		}
		
		cout<<ans<<'\n';
	
	}
} 