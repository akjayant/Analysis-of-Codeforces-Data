#include <bits/stdc++.h>
using namespace std;
void read(int &x){
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int t,n,a,b,c,d,k;
int main() {
	read(t);
	while(t--){
		read(a);read(b);read(c);read(d);read(k);
		int ans1,ans2;
		ans1=(a/c);if(a%c!=0)ans1++;
		ans2=(b/d);if(b%d!=0)ans2++;
		if(ans1+ans2>k)puts("-1");
		else printf("%d %d\n",ans1,k-ans1);
	}
	return 0;
}
