#include<bits/stdc++.h>
#define writeln(x)  write(x),puts("")
#define writep(x)   write(x),putchar(' ')
using namespace std;
inline int read(){
	int ans=0,f=1;char chr=getchar();
	while(!isdigit(chr)){if(chr=='-') f=-1;chr=getchar();}
	while(isdigit(chr)){ans=(ans<<3)+(ans<<1)+chr-48;chr=getchar();}
	return ans*f;
}void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}const int M = 1E5+5;
int f[M];
#define mod 1000000007
int main(){
	int x=read(),y=read();
	f[1]=2,f[2]=4;
	for(int i=3;i<=100000;i++)f[i]=(f[i-1]+f[i-2])%mod;
	int ans=f[x]+f[y]-2;
	ans=(ans%mod+mod)%mod;
	cout<<ans;
	return 0;
}
