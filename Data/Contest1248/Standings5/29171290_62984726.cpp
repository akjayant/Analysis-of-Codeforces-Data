#include<bits/stdc++.h>

using namespace std;
int a[200000];
int main()
{
	int n;
	cin>>n;
	long long sum=0,sum1=0;;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n/2;i++)
		sum1+=a[i];
	cout<<sum1*sum1+(sum-sum1)*(sum-sum1)<<endl;
} 
