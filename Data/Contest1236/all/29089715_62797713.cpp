#include <bits/stdc++.h>
using namespace std;
vector <int> A[301];
int n;
void lr(int l)
{
	for(int i=0;i<n;i++)
	{
		A[i].push_back(l+i);
	}
}
void rl(int r)
{
	for(int i=n-1,k=0;i>=0;i--,k++)
	{
		A[i].push_back(r+k);
	}
}
int main()
{
	
	cin>>n;
	int i=0;int key=1;
	while(i<n*n)
	{
		if(key)
			{
				lr(i);
				key=0;
			}
		else
			{
				key=1;
				rl(i);
			}
		i+=n;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<A[i][j]+1<<" ";
		cout<<"\n";
	}
	return 0;
}