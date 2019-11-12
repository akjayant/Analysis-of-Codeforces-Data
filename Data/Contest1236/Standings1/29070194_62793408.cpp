#include<bits/stdc++.h>
#define N 305
using namespace std;
int n,cnt,ans[N][N];
int main()
{
  scanf("%d",&n);cnt=n*n;
  for(int i=1;i<=n;i++)
  {
    if(i&1){
	  for(int j=1;j<=n;j++)ans[j][i]=cnt--;
	}
	else{
	  for(int j=n;j;j--)ans[j][i]=cnt--;
	}
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)printf("%d ",ans[i][j]);
    printf("\n");
  }
  return 0;
}