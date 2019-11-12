#include<bits/stdc++.h>
#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%I64d",&a)
using namespace std;
typedef long long ll;
const int maxn=1e5+50;
int arr[305][305];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			int z=n*(i-1)+1;
			for(int j=1;j<=n;j++)
			{
				arr[j][i]=z++;
			}
		}
		else
		{
			int z=n*(i-1)+1;
			z=z+n-1;
			for(int j=1;j<=n;j++)
			{
				arr[j][i]=z--;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==1) cout<<arr[i][j];
		    else cout<<" "<<arr[i][j];
		}
		cout<<endl;
	}
	return 0;
}
