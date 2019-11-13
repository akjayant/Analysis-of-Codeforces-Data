#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",3*(min(b,c>>1)+min(a,b-min(b,c>>1)>>1)));
	}
	return 0;
}

