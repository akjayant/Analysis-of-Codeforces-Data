#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int P=1e9+7;
char a[100005];
int f[100005],n;
int main(){
	scanf("%s",a+1); n=strlen(a+1); f[0]=1;
	for(int i=1;i<=n;++i){
		f[i]=f[i-1];
		if(a[i]=='u'&&a[i-1]=='u') f[i]=(f[i]+f[i-2])%P;
		if(a[i]=='n'&&a[i-1]=='n') f[i]=(f[i]+f[i-2])%P;
		if(a[i]=='m'||a[i]=='w'){puts("0"); return 0;}
	}printf("%d",f[n]);
	return 0;
}
