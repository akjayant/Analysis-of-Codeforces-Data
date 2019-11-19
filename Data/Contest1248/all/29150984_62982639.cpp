#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
inline int read(){
	int sum(0);char ch(getchar());
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum;
}
#define L long long
int n;
L a[100005],ans1,ans2,ans;
int main(){
	n=read();for(int i=1;i<=n;++i){a[i]=read();ans2+=a[i];}
	sort(a+1,a+n+1);
	for(int i=1;i<=(n>>1);++i)ans1+=a[i];
	ans2-=ans1;
	ans=ans1*ans1+ans2*ans2;
	printf("%lld",ans);
}