#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pi 3.1415926535897932
#define INF INT_MAX
#define MOD 1000000007

int main() {

	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j,ans=0;
		cin>>n;
		int a[n];
		for(i=0;i<n;++i)cin>>a[i];
		sort(a,a+n);
		for(i=0;i<n;++i)ans=max(ans,min(a[i],n-i));
		cout<<ans<<"\n";
	}

	return 0;
}