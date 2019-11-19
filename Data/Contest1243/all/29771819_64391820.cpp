#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,m,p[300],tt,len;
int main(){
	cin>>n; m=len=n;
	for(ll i=2,t=sqrt(n);i<=t;++i){
		if(m<i) break;
		if(m%i==0) p[++tt]=i;
		while(m%i==0) m/=i;
	}
	if(m>1) p[++tt]=m;
	for(int i=tt;i>=1;--i){
		if(len%p[i]){len=1; break;}
		len=p[i];
	}cout<<len;
	return 0;
}
