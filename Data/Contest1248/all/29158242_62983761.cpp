#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int n,i;
	cin>>n;
	ll int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll ans =0,t1=0,t2=0;
	for(i=0;i<n/2;i++){
		t1 += a[i];
	}
	while(i<n){
		t2 += a[i];
		i++;
	}
	t1 = t1*t1;
	t2 = t2*t2;
	ans = t1+t2;
	cout<<ans<<endl;
}