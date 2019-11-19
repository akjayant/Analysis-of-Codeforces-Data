#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long sum1=0,sum2=0,sum3=0,sum4=0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(x%2)
				sum1++;
			else
				sum2++;
		}
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(x%2)
				sum3++;
			else
				sum4++;
		}
		cout<<sum1*sum3+sum2*sum4<<endl;
	}
} 
