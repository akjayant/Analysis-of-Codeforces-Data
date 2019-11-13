#include<bits/stdc++.h>

using namespace std;
const int N=11000;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int T,a,b;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d",&a,&b);
		if (gcd(a,b)!=1) printf("Infinite\n");
		else printf("Finite\n");
	}
	return 0;
}