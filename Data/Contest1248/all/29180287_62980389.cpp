#include <bits/stdc++.h>
#define Tree int h,int l,int r
#define Left 2*h,l,(l+r)/2
#define Right 2*h+1,(l+r)/2,r
#define F first
#define S second
#define Pb push_back
using namespace std;
long long n,X,Y,a[100005];
main () {
	ios::sync_with_stdio(false);
	cin>>n;
	
	for (int i=1; i<=n; i++)
		cin>>a[i];
		
	sort(a+1,a+n+1);
	
	for (int i=n; i>=n/2+1; i--)
		X+=a[i];
		
	for (int i=n/2; i>=1; i--)
		Y+=a[i];
		
	cout<<X*X+Y*Y<<endl;
}