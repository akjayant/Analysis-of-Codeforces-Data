#include<bits/stdc++.h>
#define For(a,b,c) for(int a=b;a<=c;++a)
#define Dor(a,b,c) for(int a=b;a>=c;--a)
using namespace std;
int n;
char S[1007];
void sol() {
	scanf("%d%s",&n,S+1);
	int x=-1,y=-1;
	For(i,1,n)
	if(S[i]=='1') {
		x=i;
		break;
	}
	Dor(i,n,1)
	if(S[i]=='1') {
		y=i;
		break;
	}
	if(x==-1) {
		printf("%d\n",n);
		return;
	}
	printf("%d\n",max(2*y,2*(n-x+1)));
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) sol();
	return 0;
}