#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n;
	cin>>n;
	ll a[n*n + 1] = {0};
	
	for( int i=0;i<n*n;i++ ){
	    if( (i/n)%2 ){
	        a[i] = n - i%n;
	    }
	    else{
	        a[i] = i%n  + 1;
	    }
	}
	
	vector<int> ans[n+1];
	for( int i=0;i<n*n;i++ ){
	    ans[a[i]].push_back(i+1);
	}
	for( int i=1;i<=n;i++ ){
	    for( int j=0;j<n;j++ ){
	        cout<<ans[i][j]<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}