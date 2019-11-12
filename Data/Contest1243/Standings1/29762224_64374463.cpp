#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
	ll num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
	return num*neg;
}

bool cmp1(int x,int y){return x>y;}
int T,n,a[1010],ans;

int main(){
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(a[i]>=i)ans=i;
			else break;
		}cout<<ans<<endl;
	}return 0;
}
