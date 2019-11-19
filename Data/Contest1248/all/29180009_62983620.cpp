#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int a[100010];
signed main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int A=0,B=0;
	for(int i=0;i<n/2;i++) A+=a[i];
	for(int i=n/2;i<=n;i++) B+=a[i];
	cout<<A*A+B*B;
	return 0;
}