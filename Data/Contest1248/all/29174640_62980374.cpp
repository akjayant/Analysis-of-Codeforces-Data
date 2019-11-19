#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int T;
	T=1;
	for(int i=1;i<=T;i++)
	{
		int N;
		cin>>N;
		long long arr[N];
		for(int i=0;i<N;i++)
			cin>>arr[i];
		sort(arr,arr+N);
		long long x=0,y=0;
		for(int i=0,j=N-1;i<=j;i++,j--)
			if(i!=j)
			{
				x+=arr[j];
				y+=arr[i];
			}
			else
				x+=arr[i];
		cout<<x*x + y*y<<endl;
		
	}
}
