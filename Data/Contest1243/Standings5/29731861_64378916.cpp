#include<bits/stdc++.h>

using namespace std;

const int N = 1000 + 100;
int a[N];

int main(){
	int k; cin>>k;
	for(int kn = 0;kn<k;kn++){
		int n; cin>>n;
		for(int i = 0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		int ans = 1;
		for(int i = n-1;i > -1 ;i--)if(min(a[i],n-i) > ans)ans = min(a[i],n-i);
		cout<<ans<<"\n";
	}
	return 0;

	
}
