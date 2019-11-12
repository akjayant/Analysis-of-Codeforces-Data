#include<bits/stdc++.h>
#define N 105
using namespace std;
int T,ans,a,b,c,f[N][N][N];
void gmax(int &a,int b){a=max(a,b);}
int main()
{
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d%d",&a,&b,&c);
    memset(f,128,sizeof(f));
    f[a][b][c]=0;ans=0;
    for(int i=a;i>=0;i--)
      for(int j=b;j>=0;j--)
        for(int k=c;k>=0;k--)
        {
          ans=max(ans,f[i][j][k]);
          if(i>=1&&j>=2)gmax(f[i-1][j-2][k],f[i][j][k]+1);
          if(j>=1&&k>=2)gmax(f[i][j-1][k-2],f[i][j][k]+1);
	    }
    printf("%d\n",ans*3);
  }
  return 0;
} 