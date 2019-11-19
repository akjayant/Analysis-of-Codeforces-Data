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
int a[N],b[N];

void doit() {
    scanf("%d", &n);
    int x = 0, y = 0;
    ll re=0;
    fr(i, 1, n) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0)x++;
        re+=a[i];
    }
    sort(a+1,a+1+n);
    x=(n+1)/2;
    y=n-x;
    ll re2=0;
    fr(i,1,y){
        re2+=a[i];
    }
    re-=re2;
    printf("%lld\n",re*re+re2*re2);
}
int main(){
//    int cas;
//    scanf("%d",&cas);
//    while (cas--)
        doit();
}