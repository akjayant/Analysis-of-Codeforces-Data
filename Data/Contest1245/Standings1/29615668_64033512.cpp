#include<bits/stdc++.h>
#define regi register int
int a[10001];
double f[10001][2];
inline int read(){int r=0,w=0,c;for(;!isdigit(c=getchar());r=c);for(w=c^48;isdigit(c=getchar());w=w*10+(c^48));return r^45?w:-w;}
int toone(int x,int y){
  if(x%2==1)
	  return 10*x+y-11;
  else
	  return 10*x-y;
}
main(){
  for(regi i=1;i<=10;++i)
    for(regi j=1;j<=10;++j)
      a[toone(i,j)]=read();
  for(regi i=1;i<100;++i){
    f[i][0]=6;
    for(regi j=std::max(i-6,0);j<i;++j)
      f[i][0]+=f[j][1];
    f[i][0]/=std::min(i,6);
    f[i][1]=std::min(f[i][0],f[toone((i/10+1)-a[i],((i/10)%2==1)?(10-i%10):(i%10+1))][0]);
  }
  printf("%.10lf",f[99][1]);
}