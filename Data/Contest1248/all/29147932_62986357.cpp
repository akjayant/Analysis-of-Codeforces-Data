#include<iostream>
#include<algorithm>
using namespace std;
long long m,n,sum;
long long tree[100001];
int main()
{
	sum=0;
	m=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>tree[i];
		sum+=tree[i];
	}
	sort(tree+1,tree+1+n);
	for (int i=1;i<=n/2;i++)
	m+=tree[i];
	cout<<sum*sum-2*m*(sum-m)<<endl;
} 