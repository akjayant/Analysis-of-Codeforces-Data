#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,k,x,y;

int main(int argc,char *argv[]){
	int T;
	scanf("%d",&T);
	while(T--){
		// a=read(); b=read(); c=read(); d=read(); k=read();
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		x=a/c; y=b/d;
		if(a%c) x++;
		if(b%d) y++;
		if(x+y>k) printf("-1\n");
		else cout << x << " "<< y << endl;
	}
	return 0;
}
