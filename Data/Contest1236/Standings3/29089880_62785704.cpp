#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int t,a,b,c;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		int x=min(a,b/2);int A=a-x,B=b-2*x;int y=min(B,c/2);
		int X=min(b,c/2);B=b-X;int C=c-2*X;int Y=min(a,B/2);
		printf("%d\n",max(x*3+y*3,X*3+Y*3));
	}
	return 0;
}
