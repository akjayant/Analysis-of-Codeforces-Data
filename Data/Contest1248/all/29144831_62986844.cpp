#include<bits/stdc++.h>
#define int long long
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
}const int M = 1e5+5;
int a[M],n;
inline void Solve_1(){
	sort(a+1,a+n+1);
	int x,y,ans(0);
	x=y=0;
	for(int i=1;i<=n/2;i++)x+=a[i];
	for(int i=n/2+1;i<=n;i++)y+=a[i];
	ans=x*x+y*y;
	cout<<ans;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	Solve_1();
	return 0;
}
