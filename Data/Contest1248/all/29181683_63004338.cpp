#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include <cmath>

using namespace std;
#define  fr(i,x,y) for(int i=x;i<=y;i++)

typedef  long  long ll;
#define  N 100005

#define ms(x,y) memset(x,y,sizeof(x));
vector<int > aa;
int m,n;
char s[N];
int a[N];
int f(){
    int re=0;
    a[0]=0;
    int mi=n+1,j;
   fr(i,1,n)
   {
       if (s[i]=='(') a[i]=a[i-1]+1;
       else a[i]=a[i-1]-1;
       mi=min(mi,a[i]);
   }
    fr(i,1,n)
    if (a[i]==mi) {j=i; break;}
   // printf("%d\n",j);
    int an=0;
    a[j]=0;
    fr(i,j+1,n){
        if (s[i]=='(') a[i]=a[i-1]+1;
        else a[i]=a[i-1]-1;
        if (a[i]==0) an++;
    }
    a[0]=a[n];
    fr(i,1,j){
        if (s[i]=='(') a[i]=a[i-1]+1;
        else a[i]=a[i-1]-1;
        if (a[i]==0) an++;
    }
    if (a[j]==0)return an;
    else return 0;
}
void doit() {

    scanf("%d%s", &n,s+1);
    int tt,ma,an1,an2;
    ma=f(); an1=an2=1;


    fr(i,1,n)
    fr(j,i+1,n){
        swap(s[i],s[j]);
        tt=f();
        if (tt>ma) {
            ma=tt;
            an1=i;
            an2=j;
        }
        swap(s[i],s[j]);
    }
    printf("%d\n%d %d\n",ma,an1,an2);


}
int main(){
//    int cas;
//    scanf("%d",&cas);
//    while (cas--)
        doit();
}