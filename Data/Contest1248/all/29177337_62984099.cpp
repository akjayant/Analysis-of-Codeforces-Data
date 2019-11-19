#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long LL;
const int MAXN = 1e5+5;

int n ;
int a[MAXN];

int main(){
	cin>>n;
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	LL x1=0,y1=0;
	for(int i = 0;i<n/2;i++){
		x1+=a[i];
	}
	for(int i = n/2;i<n;i++){
		y1+=a[i];
	}
	printf("%lld\n",x1*x1+y1*y1);
	return 0;
}