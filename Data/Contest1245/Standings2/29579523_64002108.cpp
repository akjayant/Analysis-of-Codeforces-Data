#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
const double pi = acos(-1.0);

// int n > 0;
// int a,b,c >=0;


// a rock
// b paper
// c scissor

// >= (n+1)/2

char s[110];
char ans[110];
int n ;
int a,b,c;

int main(){
  int t;
  cin>>t;
  while(t--){
    scanf("%d",&n);
    scanf("%d %d %d",&a,&b,&c); // r p s
    scanf("%s",s);
    rep(i,0,n){
      if(s[i] == 'R' && b> 0){
        ans[i] = 'P';
        b--;
      }else if(s[i] == 'P' && c> 0){
        ans[i] = 'S';
        c--;
      }else if(s[i] == 'S' && a> 0){
        ans[i] = 'R';
        a--;
      }else{
        ans[i] = 0;
      }
    }
    if(a+b+c > n-(a+b+c)){
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    rep(i,0,n){
      if(ans[i] == 0){
        if(a){
          printf("R");
          a--;
        }else if(b){
          printf("P");
          b--;
        }else if(c){
          printf("S");
          c--;
        }
      }else{
        printf("%c",ans[i]);
      }
    }

    printf("\n");
  }
  return 0;
}
