#include<bits/stdc++.h>
#define ll long long
#define fr(i,x,y) for(int i=(x);i<=(y);i++)
#define rf(i,x,y) for(int i=(x);i>=(y);i--)
#define frl(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int N=1002;
const int p=998244353;
int a,b,c,d,k;

void read(int &x){ scanf("%d",&x); }

int main(){
	int T;
	read(T);
	while(T--){
		read(a);read(b);read(c);read(d);read(k);
		int xx=a/c;if (a%c) xx++;
		int yy=b/d;if (b%d) yy++;
		if (xx+yy>k) puts("-1");
		 else printf("%d %d\n",xx,yy);
	}
	return 0;
}