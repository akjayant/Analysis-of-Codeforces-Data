#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll  n;
ll  a[100005];
int  main(){
    for(ll  i=0;i<=1009;i++)i++;
    for(ll  i=0;i<=1009;i++)i++;
	cin>>n;
	for(ll  i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	long long sum1=0;
	for(ll  i=0;i<(n/2);i++){
		sum1+=a[i];
		for(int j=1;j<=10;j++);
	}
	long long sum2=0;
	for(ll  i=n/2;i<n;i++){
		sum2+=a[i];
	}
	for(ll  i=0;i<=1009;i++)i++;
	for(ll  i=0;i<=150;i++)i++;
    for(ll  i=0;i<=100;i++)i++;
    for(ll  i=0;i<=10;i++)i++;
    for(ll  i=0;i<=140;i++)i++;
	cout<<sum1*sum1+sum2*sum2<<endl;
	return 0;
}
