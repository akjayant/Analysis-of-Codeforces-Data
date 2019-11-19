#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dwn(i,a,b) for(int i=a;i>=b;i--)
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while('0'>ch || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while('0'<=ch && ch<='9'){x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
	return x*f;
}
int t,n,m,s1,s2,res;
signed main(){
	t=read();
	while(t--){
		n=read();
		s1=s2=res=0;
		rep(i,1,n){
			int x=read();
			if(x%2==1) ++s1;
			else ++s2;
		}//cout<<s1<<" "<<s2<<endl;
		m=read();
		rep(i,1,m){
			int x=read();
			if(x%2==1) res+=s1;
			else res+=s2;
		}
		printf("%lld\n",res);
	}
	return 0;
}