#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int n,m;
int main(){
	int t;cin>>t;
	while(t--){
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int x=(a+c-1)/c,y=(b+d-1)/d;
		if(x+y>k) puts("-1");
		else printf("%d %d\n",x,y);
	}
	return 0;
} 