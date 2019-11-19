#include<bits/stdc++.h>
using namespace std;
signed main() 
{
	long long n;
	cin>>n;
	vector<long long>v;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
		{
			v.push_back(i);
			while(n%i==0)n/=i;
		}
	if(n!=1) v.push_back(n);
	if(v.size()==1)
		cout<<v[0];
	else
		printf("1");
	return 0;
}
/*
15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
*/