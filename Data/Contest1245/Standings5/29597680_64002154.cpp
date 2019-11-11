#include<cctype>
#include<cstdio>
#include<cstdlib>
#define rnt register int
using namespace std;
inline void read(int &x)
{
	char c;
	while(!isdigit(c=getchar()));x=c-'0';
	while(isdigit(c=getchar()))
		x=(x<<3)+(x<<1)+c-'0';
}
inline int gcd(int x,int y)
{
	if(!y) return x;
	return gcd(y,x%y);
}
int T,x,y;
int main()
{
	read(T);
	for(;T;--T)
	{
		read(x),read(y);
		if(gcd(x,y)!=1) puts("Infinite");
		else puts("Finite");
	}
	return 0;
}