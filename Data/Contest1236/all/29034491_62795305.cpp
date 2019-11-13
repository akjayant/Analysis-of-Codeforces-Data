#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
#define M 1000000007
int main() {
	LL n;
	cin>>n;
	int ar[n][n];
	LL k=1;
	for(int i=0;i<n;i++)
	{
	    if(i%2)
	    {
	        for(int j=n-1;j>=0;j--)
	        {
	            ar[j][i]=k++;
	        }
	    }
	    else
	    {
	        for(int j=0;j<n;j++)
	        {
	            ar[j][i]=k++;
	        }
	    }
	}
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	        cout<<ar[i][j]<<" ";
	    cout<<endl;
	}
	return 0;
}
