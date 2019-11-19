#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define LL long long 
#define LD long double
int n;
LL a[100005],X,Y;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;i++)
		X+=a[i];
	for(int i=n/2+1;i<=n;i++)
		Y+=a[i];
	cout<<Y*Y+X*X<<endl;
	return 0;
}