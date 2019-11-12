#include<cstdio>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j&1)
				printf("%d ",i+j*n+1);
			else
				printf("%d ",n-i+j*n);
		}
		printf("\n");
	} 
} 