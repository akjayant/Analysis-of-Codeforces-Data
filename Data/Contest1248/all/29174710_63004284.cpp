#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int P=1e9+7; 
int n,m,a[100005];
long long tt;
int main(){
	scanf("%d%d",&n,&m); a[1]=1; a[2]=2;
	if(n<m) swap(n,m);
	for(int i=3;i<=n;++i) a[i]=(a[i-1]+a[i-2])%P;
	tt=1ll*(a[n]+a[m]-1)*2%P;
	cout<<tt;
	return 0;
} 
