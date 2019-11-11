#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#define ls root<<1
#define rs root<<1|1
using namespace std;
const int maxn=5e6+7;
const double eps=1e-6;
typedef long long ll;
const int mod = 1e9+7;

char arr[maxn];
ll a[maxn];
int main()
{
	scanf("%s",arr);
	int len=strlen(arr);
	ll res=1;
	a[1]=a[0]=1;
	for(int i=2;i<=len;i++){
		a[i]=(a[i-1]+a[i-2])%mod;
	}
	for(int i=0;i<len;i++){
		if(arr[i]=='m'||arr[i]=='w'){
			cout<<0<<endl;
			return 0;
		}
		if(arr[i]=='u'){
			int num=0,k=i;
			while(arr[k]=='u'){
				num++;
				k++;
			}
			if(num>=2){
				res=(a[num]*res%mod)%mod;
			} 
			i=k-1;
		}
		else if(arr[i]=='n'){
			int num=0,k=i;
			while(arr[k]=='n'){
				num++,k++;
			}
			if(num>=2){
				res=(a[num]*res%mod)%mod;
			}
			i=k-1;
		}
	}
	printf("%lld\n",res);
}