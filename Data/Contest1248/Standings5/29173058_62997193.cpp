#include<bits/stdc++.h>
using namespace std;
int rd(){
	int k=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
	return k;
}
#define ll long long
const int N=1000001;
int n;ll a[N],b,c;
int main(){
	n=rd();
	for(int i=1;i<=n;++i)a[i]=rd(),c+=a[i];
	sort(a+1,a+n+1);
	for(int i=n/2+1;i<=n;++i)b+=a[i];
	printf("%lld\n",b*b+(c-b)*(c-b));
	return 0;
}