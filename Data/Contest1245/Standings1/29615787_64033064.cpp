#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
long long s[35][3][3];
bool vis[35][3][3];
long long f(int p,bool l1,bool l2)
{
  if (p<0)return 1;
  if (vis[p][l1][l2])return s[p][l1][l2];
  vis[p][l1][l2]=1;
  bool lim1,lim2;
  lim1=l1&&!(n&(1<<p));
  lim2=l2&&!(m&(1<<p));
  s[p][l1][l2]=f(p-1,lim1,lim2);
  if (!lim1)
    s[p][l1][l2]+=f(p-1,l1,lim2);
  if (!lim2)
    s[p][l1][l2]+=f(p-1,lim1,l2);
  return s[p][l1][l2];
}
long long calc(int _n,int _m)
{
  if (_n<0||_m<0)return 0;
  n=_n;m=_m;
  for (int i=0;i<=31;i++)
    vis[i][0][0]=vis[i][0][1]=vis[i][1][0]=vis[i][1][1]=0;
  return f(30,1,1);
}
int main()
{
  int T;scanf("%d",&T);
  while(T--){
    int l,r;
    scanf("%d%d",&l,&r);
    printf("%I64d\n",calc(r,r)-2*calc(r,l-1)+calc(l-1,l-1));
  }return 0;
}
