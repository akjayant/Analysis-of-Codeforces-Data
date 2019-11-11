#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std ;
typedef long long ll ;
const int maxn = 1e5 + 5 ;
const int maxm = 35 ;
const ll mod = 1e5 + 7 ;
int gcd(int a,int b)
{
    int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
	int t ;
	scanf("%d" , &t) ;
	while(t --)
	{
		int a , b ;
		scanf("%d%d" , &a , &b) ;
		if(gcd(a , b) == 1)
		  printf("Finite\n") ;
		else
		  printf("Infinite\n") ;
	}
}