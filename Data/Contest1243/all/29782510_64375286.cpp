#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define p2(a,b) cout<<a<<" "<<b<<endl;
#define p3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;	
#define all(a) a.begin(),a.end()
#define M 1000000007

	
int main(){
	fastio;
	int t,n,i;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n];
		for(i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		for(i=1;i<=n;i++){
			if(a[n-i]<i) break;
		}
		cout<<i-1<<"\n";
	}
	return 0;
}