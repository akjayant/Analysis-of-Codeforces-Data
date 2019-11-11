#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iostream>
#define test freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
	//test
	int T;
	cin>>T;
	while(T--)
	{
		int a,b;
		cin>>a>>b;
		if(__gcd(a,b)==1) puts("Finite");
		else puts("Infinite");
	}

	return 0;
}