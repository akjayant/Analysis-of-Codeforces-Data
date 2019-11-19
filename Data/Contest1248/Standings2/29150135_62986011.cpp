#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100007];
int read()
{
	int x=0;char ch;ch=getchar();
	while(ch<'0' or ch>'9') ch=getchar();
	while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
void readArray(int a[],int n)
{
	for(int i=1;i<=n;i++) a[i]=read();
} 
signed main()
{
    int n,A=0,B=0;
    n=read();
    readArray(a,n);
    sort(a+1,a+n+1);
    for(int i=1;i<=n/2;i++) A+=a[i];
    for(int i=n/2+1;i<=n;i++) B+=a[i];
    cout<<B*B+A*A<<endl;
}