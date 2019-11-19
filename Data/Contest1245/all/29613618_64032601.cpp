#include<bits/stdc++.h>
using namespace std;
const int N = 11;
#define nfr(i,a,b) for(register int i = a;i >= b; --i)
#define fr(i,a,b) for(register int i = a;i <= b; ++i)

int a[N][N];
double f[N][N][2];

void init(){
   fr(i,1,10){
      fr(j,1,10){
         scanf("%d",&a[i][j]);
      }
   }
}

int nxtx(int x,int y,int st){
   if(x%2 == 0){
      if(y+st > 10)return x-1;
      else return x;
   } else {
      if(y-st <= 0)return x-1;
      else return x;
   }
}

int nxty(int x,int y,int st){
   if(x%2 == 0){
      if(y+st > 10)return 11-((y+st-1)%10+1);
      else return y+st;
   } else {
      if(y-st <= 0)return 1-y+st;
      else return y-st;
   }
}

void solve(){
   memset(f,0,sizeof f);
   f[1][1][0] = f[1][1][1] = 0;
   fr(i,2,6)f[1][i][0] = f[1][i][1] = 6;
   fr(i,7,10){
      fr(j,1,6){
         f[1][i][0] += (f[1][i-j][0]+1)/6.0;
         f[1][i][1] += (f[1][i-j][1]+1)/6.0;
      }
   }
   fr(i,2,10){
      if(i%2 == 1){
         fr(j,1,10){
            fr(w,1,6)f[i][j][1] += (f[nxtx(i,j,w)][nxty(i,j,w)][0]+1)/6.0; 
            f[i][j][0] = f[i][j][1];
            if(a[i][j] > 0)f[i][j][0] = min(f[i][j][0],f[i-a[i][j]][j][1]);
         }
      } else {
         nfr(j,10,1){
            fr(w,1,6)f[i][j][1] += (f[nxtx(i,j,w)][nxty(i,j,w)][0]+1)/6.0;
            f[i][j][0] = f[i][j][1];
            if(a[i][j] > 0)f[i][j][0] = min(f[i][j][0],f[i-a[i][j]][j][1]);
         }
      }
   }
   printf("%.10lf\n",f[10][1][1]);
}

int main(){
   init(); solve();
   return 0;
}
