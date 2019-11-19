#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<stack>
#include<vector>
#include<set>
using namespace std;
const int inf=0x3f3f3f3f;
const int M=600010;
const int N=1010;
inline int read(void){
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
int t,a,b,c,d,k; 
signed main(void){
	t=read();
	while (t--){
		a=read(),b=read(),c=read(),d=read(),k=read();
		int ans=a/c+((a%c)>=1)+b/d+((b%d)>=1);
		if (ans>k) printf("-1\n");
		else{
			printf("%d %d\n",a/c+((a%c)>=1),b/d+((b%d)>=1));
		}
	}
	return 0;
}