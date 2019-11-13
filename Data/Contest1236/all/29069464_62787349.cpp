#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main(){
	int cas=read();
	while(cas--){
		int a=read(),b=read(),c=read();
		int ans=0;
		if(b>=1&&c>=2){
			int cnt=min(b,c/2);
			ans+=cnt*3;
			b-=cnt;
			cnt=min(a,b/2);
			ans+=cnt*3;
		}else if(a>=1&&b>=2){
			int cnt=min(a,b/2),temp=0;
			temp+=cnt*3;
			b-=2*cnt;
			cnt=min(b,c/2);
			temp+=cnt*3;
			ans=max(ans,temp);
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
