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
int T,a[M],b[M],s[2],n,m;
signed main(){
	T=read();
	while(T--){
		s[0]=s[1]=0;
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}m=read();
		for(int i=1;i<=m;i++){
			b[i]=read();
			++s[b[i]%2];
		}int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]%2==0){
				ans+=s[0];
			}else ans+=s[1];
		}
		cout<<ans<<endl;
	}
	return 0;
}
