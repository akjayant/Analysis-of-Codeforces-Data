#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include <iostream>
#define LL long long
using namespace std;

int a[1000005];

int main(int argc, char const *argv[])
{
	int n; cin>>n;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	LL len1=0,len2=0;
	for (int i=1; i<=n/2; i++) len1+=a[i];
	for (int i=n/2+1; i<=n; i++) len2+=a[i];
	cout<<len1*len1+len2*len2<<endl; 
	return 0;
}