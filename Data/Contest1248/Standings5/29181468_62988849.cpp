#include<bits/stdc++.h>
using namespace std;
int a[1010000],a2[1010100]; long long b,n,m;
main(){
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i],b+=a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>n/2;i--)m+=a[i];

	cout<<m*m+(b-m)*(b-m);
} 
