#include<bits/stdc++.h>
#define maxl 300010

using namespace std;

int n,m,ans;
int a,b; 
char s[maxl];


inline void prework()
{
	scanf("%d%d",&a,&b);
}

inline void mainwork()
{

}

inline void print()
{
	if(__gcd(a,b)!=1)
		puts("Infinite");
	else
		puts("Finite");
}

int main()
{
	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{ 
		prework();
		mainwork();
		print();
	}
	return 0;
}
