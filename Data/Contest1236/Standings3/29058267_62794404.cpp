#include <bits/stdc++.h>

using namespace std;

int arr[305][305];

int main()
{
	int n;
	cin >> n;
	int cur=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			arr[i][j]=cur++;
		if(i%2)
		{
			reverse(arr[i],arr[i]+n);
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cout << arr[j][i] << " \n"[j==n-1];
}