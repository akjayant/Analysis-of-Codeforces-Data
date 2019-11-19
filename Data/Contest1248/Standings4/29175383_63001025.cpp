#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
const int SIZE=1e5+50;
int arr[SIZE];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	int maxx=max(n,m);
	arr[1]=2;arr[2]=4;
	//	printf("maxx=%d\n",maxx);
	for(int i=3;i<=maxx;i++){
		arr[i]=(arr[i-1]%MOD+arr[i-2]%MOD)%MOD;
	}
	printf("%d\n",(arr[m]+arr[n]-arr[1])%MOD);
}