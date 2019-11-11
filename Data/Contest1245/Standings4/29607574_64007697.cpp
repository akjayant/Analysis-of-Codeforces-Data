#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=100000+10,mod=1e9+7;
void in(int &x){
	char ch=getchar();int flag=0;x=0;
	while(ch<'0'||ch>'9')flag|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
	if(flag)x=-x;
}
int f[N];
string a;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	f[1]=1;f[2]=2;f[3]=3;
	for(int i=4;i<=N-5;i++){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	cin>>a;
	long long ans=1,len=a.size();
	int flag=0;
	for(int i=0;i<len;i++){
		if(a[i]=='m'||a[i]=='w')flag=1;
		else{
			int len=1;
			if(a[i]=='u')while(a[i]=='u'&&a[i+1]=='u')i++,len++;
			else if(a[i]=='n')while(a[i]=='n'&&a[i+1]=='n')i++,len++;
			ans=(ans*f[len])%mod;
		}
	}
	if(flag)puts("0");
	else printf("%I64d\n",ans);
	return 0;
}
/*
1 2 3 4 5
0 2 3 5 8
nnnnn
nnnm
mnnn
nmnn
nnmn
nmm
mnm
mmn
*/ 


