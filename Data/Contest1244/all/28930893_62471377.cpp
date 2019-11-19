#include<bits/stdc++.h>
#define ll long long
#define fr(i,x,y) for(int i=(x);i<=(y);i++)
#define rf(i,x,y) for(int i=(x);i>=(y);i--)
#define frl(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int N=2002;
const int p=998244353;
int n;
char c[N];

void read(int &x){ scanf("%d",&x); }

int main(){
	int T;
	read(T);
	while(T--){
		read(n);
		scanf("%s",c+1);
		int L=0,r=0;
		fr(i,1,n) if (c[i]=='1'){ L=i;break; }
		rf(i,n,1) if (c[i]=='1'){ r=i;break; }
		if (L==0&&r==0) printf("%d\n",n);
		 else if (L==r) printf("%d\n",2*max(L,n-L+1));
		  else{
		  	int xx=max(L,n-r+1);
		  	int ans=max(n+r-L+1,2*(r-L+1)+xx-1);
		  	ans=max(ans,max(2*r,2*(n-L+1)));
		  	printf("%d\n",ans);
		  }
	}
	return 0;
}