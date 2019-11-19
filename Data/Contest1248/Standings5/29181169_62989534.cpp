#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,a[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=n/2;
	long long s1=0,s2=0;
	for(int i=1;i<=j;++i){
		s1+=a[i];
	}
	for(int i=j+1;i<=n;++i){
		s2+=a[i];
	}
	long long ans=s1*s1+s2*s2;
	s1+=a[j+1],s2-=a[j+1];
	long long ans2=s1*s1+s2*s2;
	if(n%2==0)ans2=0;
	cout<<max(ans,ans2);
} 