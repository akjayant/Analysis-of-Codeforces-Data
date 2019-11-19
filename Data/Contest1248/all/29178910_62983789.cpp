#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn =  1e5+10;
int save[maxn];


int n;

int main()
{
	scanf("%d",&n);
	for(int i  =1;i<=n;i++)
		scanf("%d",save+i);
	sort(save+1,save+1+n);
	int num = n/2;
	long long a = 0,b = 0;
	for(int i = 1;i<=num;i++)
		b+=save[i];
	for(int i = num+1;i<=n;i++)
		a+=save[i];
	cout<<a*a+b*b;





	return 0;
}
