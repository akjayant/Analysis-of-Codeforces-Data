#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int N,M;
		cin>>N;
		long long  o1=0,o2=0,e1=0,e2=0;
		for(int i=0;i<N;i++)
		{
			int temp;
			cin>>temp;
			if(temp%2==0)
				e1++;
			else
				o1++;
		}
		cin>>M;
		for(int i=0;i<M;i++)
		{
			int temp;
			cin>>temp;
			if(temp%2==0)
				e2++;
			else
				o2++;
		}
		long long ans=o1*o2 + e1*e2;
		cout<<ans<<endl;
		
	}
}
