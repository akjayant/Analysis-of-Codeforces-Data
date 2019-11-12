#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5; 
#define pb pop_back
#define ps push_back
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f; 
}
inline void chkmin(int &x,int y){if(y<x) x=y;}
inline void chkmax(int &x,int y){if(y>x) x=y;}
int main(){
	int t=read();
	while(t--){
		int a=read(),b=read(),c=read();
		int ans=0;
		while(b>0&&c>1) {
			b--,c-=2;
			ans+=3;
		}
		while(a>0&&b>1) {
			a--,b-=2;
			ans+=3;
		}
		cout<<ans<<endl;
	}
	return 0;
}