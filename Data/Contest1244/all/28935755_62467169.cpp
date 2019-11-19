#include <bits/stdc++.h>
#include <algorithm>
#define pi 3.14159265358
using namespace std;
typedef long long ll;
const ll mod=1000000007;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const int maxn = 3e6 + 5;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main(){
	int t,a,b,c,d,k;
	t=read();
	while(t--){
		a=read();
		b=read();
		c=read();
		d=read();
		k=read();
		int ans1=0,ans2=0;
		ans1+=a/c;
		ans2+=b/d;
		if(a%c!=0)
			ans1++;
		if(b%d!=0)
			ans2++;
		if(ans1+ans2>k){
			printf("-1\n");
		}
		else{
			printf("%d %d\n",ans1,ans2);
		}
	}
}