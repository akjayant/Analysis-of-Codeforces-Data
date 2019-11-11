#include<algorithm>
#include<iostream>
#include<complex>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<ctime>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define N 10039
#define mod 20070831
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int t,A,B;
int gcd(int i,int j)
{
	return !j ? i : gcd(j,i%j);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&A,&B);
		if(gcd(A,B)==1) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}
/*Kamii_Sinogi*/