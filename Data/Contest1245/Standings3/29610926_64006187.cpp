#include<bits/stdc++.h>
using namespace std;
char str[200];
int main(){
  int t,n,a,b,c,r,p,s;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    scanf("%d%d%d",&a,&b,&c);
    scanf(" %s",str);
    r=0;p=0;s=0;
    for(int i=0;i<n;i++){
      if(str[i]=='R')r++;
      if(str[i]=='P')p++;
      if(str[i]=='S')s++;
    }
    if(min(a,s)+min(b,r)+min(c,p)>=n/2+(n%2)){
      printf("YES\n");
      for(int i=0;i<n;i++){
        if(str[i]=='R'){
          if(b){
            printf("P");
            b--;
          }
          else if(a>s){
            printf("R");
            a--;
          }
          else if(c>p){
            printf("S");
            c--;
          }
          r--;
        }
        if(str[i]=='P'){
          if(c){
            printf("S");
            c--;
          }
          else if(a>s){
            printf("R");
            a--;
          }
          else if(b>r){
            printf("P");
            b--;
          }
          p--;
        }
        if(str[i]=='S'){
          if(a){
            printf("R");
            a--;
          }
          else if(b>r){
            printf("P");
            b--;
          }
          else if(c>p){
            printf("S");
            c--;
          }
          s--;
        }
      }
      printf("\n");
    }
    else printf("NO\n");
  }
  return 0;
}
