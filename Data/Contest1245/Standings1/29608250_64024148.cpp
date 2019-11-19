#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=20;
int h[maxn][maxn],d[maxn][maxn];
double f[maxn][maxn][2];
pair<int,int> pos[maxn*maxn];
/*
void print(int a[maxn][maxn]){
  for(int i=1;i<=10;i++){
    for(int j=1;j<=10;j++)printf("%d ",a[i][j]);
    printf("\n");
  }
}
*/
int main(){
  for(int i=1;i<=10;i++)
    for(int j=1;j<=10;j++)
      scanf("%d",&h[i][j]);
  for(int i=1;i<=10;i++){
    if(i&1){
      if(i>1)d[i][1]=d[i-1][1]+1;
      for(int j=2;j<=10;j++)
        d[i][j]=d[i][j-1]+1;
    }else{
      d[i][10]=d[i-1][10]+1;
      for(int j=9;j>=1;j--)
        d[i][j]=d[i][j+1]+1;
    }
  }
  for(int i=1;i<=10;i++)
    for(int j=1;j<=10;j++)
      pos[d[i][j]]=make_pair(i,j);
  for(int k=0;k<100;k++){
    int i=pos[k].first,j=pos[k].second;
    for(int l=0;l<2;l++){
      if(i==1&&j==1)continue;
      int cnt=0;double sum=0;
      for(int r=1;r<=6;r++){
        if(d[i][j]<r)cnt++;
        else{
          pair<int,int> to=pos[d[i][j]-r];
          sum+=f[to.first][to.second][0];
        }
      }
      f[i][j][l]=(sum+6)/(6-cnt);
      if(h[i][j]&&!l)
        f[i][j][l]=min(f[i][j][l],f[i-h[i][j]][j][1]);
    }
  }
  printf("%.10lf\n",f[10][1][0]);
  return 0;
}