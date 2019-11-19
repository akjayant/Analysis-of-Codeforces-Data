#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[100005];
long long x,y,s;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;++i) x+=a[i];
	for(int i=n/2+1;i<=n;++i) y+=a[i];
	
	s=x*x+y*y;
	cout<<s;
	return 0;
}
