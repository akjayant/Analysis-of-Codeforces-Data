#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long 
using namespace std;
inline int read(){
	int f=1,ans=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return f*ans;
}
const int MAXN=1000011;
int n,fdsfsdf[MAXN],sum,saddsadsa,sadadsad,l,r;
bool cmp(int fdsfsdf,int dsadsa){return fdsfsdf>dsadsa;}
signed main(){
	n=read();
    for(int i=1;i<=n;i++) fdsfsdf[i]=read();
    sort(fdsfsdf+1,fdsfsdf+n+1,cmp);l=1,r=n;for(;l<r;l++,r--)saddsadsa+=fdsfsdf[l],sadadsad+=fdsfsdf[r];
    if(l==r) saddsadsa+=fdsfsdf[l];printf("%I64d",saddsadsa*saddsadsa+sadadsad*sadadsad);
    return 0;
}